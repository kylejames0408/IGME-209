// UNIQUE FEATURE(S) DOCUMENTATION
// 
// - Added replayability (makes the gamestates cycle through without having to get out of the game)
//		- Resets all values
//		- Directs user how to replay game at the end
//		- Shows the main menu again (in case the user forgets how to play)
//		- Lines 181-195 in main.cpp
// 
// 
// - Added sounds & music
//		- Tutorial from https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
//		- Linking Tutorial https://www.sfml-dev.org/faq.php#build-link-static
//		- Crunching Sound - "Chewing, Breadstick, Single, B.wav" by InspectorJ (www.jshaw.co.uk) of Freesound.org
//		- Bedtime Stories - https://youtu.be/XVHVFwwuOa0 (Ross Bugden)
//		- Included Audio from SFML | Line 38
//		- Load Audio | Lines 155-161
//		- Play Sound | Lines 302-303
//		- Play Music | Lines 163-165

// General Inclusions
#include <iostream>
#include <time.h>
#include <math.h>
#include <string>

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
#include <SFML/Audio.hpp>

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

	// Call the game wrapper to start the game cycle
	gameWrapper();

	// Check for memory leaks
	_CrtDumpMemoryLeaks();
}

// Methods
/// <summary>
/// Game Wrapper to contain the game code and prevent false positive memory leak detection.
/// </summary>
void gameWrapper()
{
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
	snakeDef.position.Set(0.0f, -8.0f);
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

	// World updating variables
	sf::Clock deltaClock;
	sf::Time deltaTime;

	// Tracking the snake's previous and original (when target moves) position
	b2Vec2 snakePrevPosition;
	b2Vec2 snakeOriginalPosition = snake->GetPosition();

	// Prepare the game area
	unsigned short targetsHit = 0;
	moveTarget(&targetPosition);
	long score = 0;
	bool started = false;

	// Get the first distance of target from the snake
	float averageStartingDistance = sqrt(pow(snakeOriginalPosition.x - targetPosition.x, 2) + pow(snakeOriginalPosition.y - targetPosition.y, 2));

	// Prepare SFML font
	sf::Font font;
	font.loadFromFile("ShareTechMono.ttf");

	// Prepare SFML audio
	sf::SoundBuffer buffer;
	buffer.loadFromFile("crunch.wav");
	sf::Sound crunchSound;
	crunchSound.setBuffer(buffer);
	sf::Music music;
	music.openFromFile("bedtimestories.wav");

	// Play and loop the music
	music.setLoop(true);
	music.play();

	// Create the Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Graphical Snake");

	// Run the program as long as the window is open
	while (window.isOpen())
	{
		// Check all of the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "Close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			// If there is a keypress
			if (event.type == sf::Event::KeyPressed)
			{
				// If the spacebar is pressed, reset default values
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					started = false;
					targetsHit = 0;
					score = 0;
					averageStartingDistance = 0;
					snake->SetActive(true);
					snake->SetTransform(b2Vec2(0.0f, -8.0f), snake->GetAngle());
					moveTarget(&targetPosition);
				}
			}
		}

		#pragma region Menu

		// Allow the user to read the game instructions and consent to the rules before starting
		while (!started && window.isOpen())
		{
			// Clear the window with black color
			window.clear(sf::Color::Black);

			// Create and draw the title
			sf::Text title;
			title.setFont(font);
			title.setString("Gravity Snake");
			title.setCharacterSize(48);
			title.setFillColor(sf::Color::Red);
			title.setPosition(sf::Vector2f(225, 0));
			window.draw(title);

			// Create and draw the controls
			sf::Text instructions;
			instructions.setFont(font);
			instructions.setString("Controls:\n   - W: Move up\n   - A: Move left\n   - S: Move down\n   - D: Move right\n   - ESC: End the game early");
			instructions.setCharacterSize(24);
			instructions.setFillColor(sf::Color::Red);
			instructions.setPosition(sf::Vector2f(50, 200));
			window.draw(instructions);

			// Create and draw the rules
			sf::Text rules;
			rules.setFont(font);
			rules.setString("Rules:\n   - Hit the target twice to win!");
			rules.setCharacterSize(24);
			rules.setFillColor(sf::Color::Red);
			rules.setPosition(sf::Vector2f(50, 100));
			window.draw(rules);

			// Create and draw pts (press to start)
			sf::Text pts;
			pts.setFont(font);
			pts.setString("Press SPACE to Start!");
			pts.setCharacterSize(32);
			pts.setFillColor(sf::Color::Red);
			pts.setPosition(sf::Vector2f(225, 500));
			window.draw(pts);

			// End the current frame
			window.display();

			// Check all of the window's events that were triggered since the last iteration of the loop
			while (window.pollEvent(event))
			{
				// "Close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();

				// If there is a keypress
				if (event.type == sf::Event::KeyPressed)
				{
					// If the spacebar is pressed, start the game
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						started = true;
				}
			}
		}

		#pragma endregion

		#pragma region Game

		// Run the game
		while (targetsHit < 2 && window.isOpen())
		{
			// Update the Box2D world
			update(&deltaClock, &deltaTime, &world);

			// Check all of the window's events that were triggered since the last iteration of the loop
			while (window.pollEvent(event))
			{
				// "Close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();

				// If there is a keypress, call the applyForces function
				if (event.type == sf::Event::KeyPressed)
				{
					// Run it through the applied forces
					applyForces(snake);

					// Increment score
					score++;
				}
			}

			// If the snake is set to sleep, exit the game
			if (!snake->IsActive())
				break;

			// Get previous snake position
			snakePrevPosition = snakePosition;

			// Check the distance between the snake and the target. If they are within the distance, move the target elsewhere.
			snakePosition = snake->GetPosition();
			float distance = sqrt(pow(snakePosition.x - targetPosition.x, 2) + pow(snakePosition.y - targetPosition.y, 2));
			if (distance <= 0.5)
			{
				// Play the crunch sound
				crunchSound.play();

				// Increment the targets hit
				targetsHit++;

				// If the game isn't over
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

			// Display the current positions (if the snake has moved and the game isn't already over) [DEBUG ONLY]
			//if (snakePrevPosition != snakePosition && targetsHit < 2)
			//	display(targetPosition, snakePosition);

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
				//cout << "COMPOSITE SCORE: " << score << endl; // [DEBUG ONLY]
			}

			// Clear the window with black color
			window.clear(sf::Color::Black);

			// Update Display
			// Draw everything here...
			// window.draw(...);

			// SCALE
			// box2d -> sfml coordinate system:
			//	x: x*(40) + 400  -- half-window (400) divided by max box2d (10) plus the half-window (400) multiplied by the box2d x-position
			//	y: y*(-30) + 300 -- half-window (300) divided by min box2d (-10) plus the half-window (300) multiplied by the box2d y-position
			//	
			//	Note: Must subtract the half-window addition by the shape's definition
			
			// Create & draw the target
			sf::RectangleShape targetShape(sf::Vector2f(10, 10)); // Create box-shaped target with length 10 and height 10
			targetShape.setPosition(targetPosition.x * 40 + 395, targetPosition.y * -30 + 295);
			targetShape.setFillColor(sf::Color::Red);
			window.draw(targetShape);

			// Create & draw the snake
			sf::RectangleShape snakeShape(sf::Vector2f(20, 20)); // Create box-shaped snake with length 20 and height 20
			snakeShape.setPosition(snake->GetPosition().x * 40 + 390, snake->GetPosition().y * -30 + 290);
			snakeShape.setFillColor(sf::Color::White);
			window.draw(snakeShape);

			// Create & draw the floor
			sf::RectangleShape groundShape(sf::Vector2f(800, 20)); // Create the box-shaped ground with length 800 and height 20
			groundShape.setPosition(0, groundBody->GetPosition().y * -30 - 20);
			groundShape.setFillColor(sf::Color::Green);
			window.draw(groundShape);

			// Create & draw the ceiling
			sf::RectangleShape ceilingShape(sf::Vector2f(800, 20)); // Create the box-shaped ground with length 800 and height 20
			ceilingShape.setPosition(0, ceilingBody->GetPosition().y * -30 + 600);
			ceilingShape.setFillColor(sf::Color::Green);
			window.draw(ceilingShape);

			// Create & draw the left wall
			sf::RectangleShape leftWallShape(sf::Vector2f(30, 600)); // Create the box-shaped ground with length 30 and height 600
			leftWallShape.setPosition(leftWallBody->GetPosition().x * 40 + 800, 0);
			leftWallShape.setFillColor(sf::Color::Green);
			window.draw(leftWallShape);

			// Create & draw the right wall
			sf::RectangleShape rightWallShape(sf::Vector2f(30, 600)); // Create the box-shaped ground with length 30 and height 600
			rightWallShape.setPosition(rightWallBody->GetPosition().x * 40 - 30, 0);
			rightWallShape.setFillColor(sf::Color::Green);
			window.draw(rightWallShape);

			// End the current frame
			window.display();
		}

		#pragma endregion

		#pragma region Game Over

		// Clear the window with black color
		window.clear(sf::Color::Black);

		// Display that the game's over
		sf::Text gameOverText;
		gameOverText.setFont(font);
		gameOverText.setCharacterSize(48);
		gameOverText.setFillColor(sf::Color::Red);
		gameOverText.setPosition(sf::Vector2f(150, 50));

		// Display the user's score
		sf::Text scoreText;
		scoreText.setFont(font);
		scoreText.setFillColor(sf::Color::Red);
		scoreText.setPosition(sf::Vector2f(225, 276));
		scoreText.setCharacterSize(32);

		// If the user didn't exit the game
		if (snake->IsActive())
		{
			// Set the game over text
			gameOverText.setString("Game Over! You Win!");

			// Set the score text
			string scoreString = "Score: " + to_string(score) + "\nPress SPACE to play again!";
			scoreText.setString(scoreString);
		}
		else
		{
			// Set the game over text
			gameOverText.setString("Game Over! Quitter!");

			// Set the score text
			scoreText.setString("Press SPACE to play again!");
		}

		// Always show the game over text
		window.draw(gameOverText);
		window.draw(scoreText);

		// End the current frame
		window.display();

		#pragma endregion
	}
}