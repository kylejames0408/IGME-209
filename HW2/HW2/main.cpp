// General Inclusions
#include <iostream>
#include <conio.h>
#include <time.h>
#include <math.h>

// Memory Leak Detection Inclusions
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// Box2D Inclusions
#include <Box2D/Box2D.h>

// SFML Inclusions
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Custom Inclusions
#include "snake.h"

// Using Statements
using namespace std;

// Method Declarations
/// <summary>
/// Game Wrapper to contain the game code and prevent false positive memory leak detection.
/// </summary>
void gameWrapper();

/// <summary>
/// The main method to run the application.
/// </summary>
/// <returns>0 - The Console Application</returns>
int main()
{
	// Seed random by passing it the current time
	srand(time(NULL));

	// Introduce the game to the user with instructions as to the keys to press
	cout << "Let's play Gravity Snake!" << endl;
	cout << "	KEYBINDS: W, A, S, D to Move or ESC to end the game early" << endl;
	cout << "	RULES: Hit the target twice to win!" << endl;

	// Wait for them to start the game
	cout << "\nPress SPACE to start!\n" << endl;
	
	// Call the game wrapper to start the game cycle
	gameWrapper();

	// Let them know the game ended
	cout << "================GAME ENDED================" << endl;

	// Hold the window open for the user to see total output
	cout << "\nPRESS ESC TO CLOSE WINDOW" << endl;
	bool exit = false;
	while (!exit)
	{
		if (_kbhit())
		{
			char input = _getch();

			switch (input)
			{
				case 27: // escape
					exit = true;
					break;

				default:
					break;
			}
		}
	}

	// Check for memory leaks
	_CrtDumpMemoryLeaks();
}

// Methods
/// <summary>
/// Game Wrapper to contain the game code and prevent false positive memory leak detection.
/// </summary>
void gameWrapper()
{
	// Allow the user to read the game instructions and consent to the rules before starting
	bool started = false;
	while (!started)
	{
		if (_kbhit())
		{
			char input = _getch();

			switch (input)
			{
				case 32: // spacebar
					started = true;
					break;

				case 27: // escape
					return;
					break;

				default:
					break;
			}
		}
	}

	// Create your physics world (b2world).
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);

	// Create walls using bodies with polygons to bound your world (b2body + b2PolygonShape)
	// Create our ground floor (yMin = -10)
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -20.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(20.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Create our ceiling (yMax = 10)
	b2BodyDef ceilingBodyDef;
	ceilingBodyDef.position.Set(0.0f, 20.0f);
	b2Body* ceilingBody = world.CreateBody(&ceilingBodyDef);

	b2PolygonShape ceilingBox;
	ceilingBox.SetAsBox(20.0f, 10.0f);
	ceilingBody->CreateFixture(&ceilingBox, 0.0f);

	// Create our left wall (xMin = -10)
	b2BodyDef leftWallBodyDef;
	leftWallBodyDef.position.Set(-20.0f, 0);
	b2Body* leftWallBody = world.CreateBody(&leftWallBodyDef);

	b2PolygonShape leftWallBox;
	leftWallBox.SetAsBox(10.0f, 20.0f);
	leftWallBody->CreateFixture(&leftWallBox, 0.0f);

	// Create our right wall (xMax = 10)
	b2BodyDef rightWallBodyDef;
	rightWallBodyDef.position.Set(20.0f, 0);
	b2Body* rightWallBody = world.CreateBody(&rightWallBodyDef);

	b2PolygonShape rightWallBox;
	rightWallBox.SetAsBox(10.0f, 20.0f);
	rightWallBody->CreateFixture(&rightWallBox, 0.0f);

	// Create your snake (b2body + b2PolygonShape)
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(0.0f, 5.0f);
	b2Body* snake = world.CreateBody(&snakeDef);

	b2PolygonShape dynamicSnake;
	dynamicSnake.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicSnake;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	snake->CreateFixture(&fixtureDef);

	// Setup the target your player will need to reach (b2Vec2)
	b2Vec2 targetPosition;
	b2Vec2 snakePosition = b2Vec2();

	// Create a while loop to keep running until the user hits ESC or you get the total number of targets
	bool escape = false;
	unsigned short targetsHit = 0;
	moveTarget(&targetPosition);

	// World updating variables
	sf::Clock deltaClock;
	sf::Time deltaTime;

	// Tracking the snake's previous and original (when target moves) position
	b2Vec2 snakePrevPosition;
	b2Vec2 snakeOriginalPosition = snake->GetPosition();

	// Get the first distance of target from the snake
	float averageStartingDistance = sqrt(pow(snakeOriginalPosition.x - targetPosition.x, 2) + pow(snakeOriginalPosition.y - targetPosition.y, 2));

	// Track the score
	short score = 0;

	while (targetsHit < 2 && !escape)
	{
		// Update the Box2D world
		update(&deltaClock, &deltaTime, &world);

		// If there is a keypress, call the applyForces function
		if (_kbhit())
		{
			// Run it through the applied forces
			applyForces(snake);

			// If the snake is set to sleep, exit the game
			if (!snake->IsAwake())
				return;

			// Increment score
			score++;
		}

		// Get previous snake position
		snakePrevPosition = snakePosition;

		// Check the distance between the snake and the target. If they are within the distance, move the target elsewhere.
		snakePosition = snake->GetPosition();
		float distance = sqrt(pow(snakePosition.x - targetPosition.x, 2) + pow(snakePosition.y - targetPosition.y, 2));
		if (distance <= 0.05)
		{
			cout << "================TARGET HIT================" << endl;
			targetsHit++;
			if (targetsHit < 2)
			{
				// Get the original position of the snake 
				snakeOriginalPosition = snakePosition;

				// Move the target
				moveTarget(&targetPosition);

				// Add the original distance to the averageStartingDistance
				averageStartingDistance += sqrt(pow(snakeOriginalPosition.x - targetPosition.x, 2) + pow(snakeOriginalPosition.y - targetPosition.y, 2));
			}
		}

		// Display the current positions (if the snake has moved and the game isn't already over)
		if (snakePrevPosition != snakePosition && targetsHit < 2)
			display(targetPosition, snakePosition);

		// If the user finishes the game
		if (targetsHit >= 2)
		{
			// Calculate the average starting distance
			averageStartingDistance /= targetsHit;

			// Report the score components [DEBUG ONLY]
			//cout << "KEY PRESSES: " << score << endl;
			//cout << "AVERAGE STARTING DISTANCE: " << averageStartingDistance << endl;

			// Calculate composite score
			// ASD / KEY PRESSES [more key presses per ASD, lower score -- more points for most efficient path to the target]
			score = (averageStartingDistance / score) * SHRT_MAX;

			// Report the composite score
			cout << "COMPOSITE SCORE: " << score << endl;
		}
	}
}