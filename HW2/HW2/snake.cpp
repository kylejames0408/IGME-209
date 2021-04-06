// General Inclusions
#include <iostream>
#include <conio.h>

// Box2D Inclusions
#include <Box2D/Box2D.h>

// SFML
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Custom Inclusions
#include "snake.h"

// Using Statements
using namespace std;

/// <summary>
/// Update the physics world.
/// </summary>
/// <param name="clock">The Clock to track time.</param>
/// <param name="time">The Time change since last tick.</param>
/// <param name="world">The phsysics world.</param>
void update(sf::Clock* clock, sf::Time* time, b2World* world)
{
	// Gets the DeltaTime
	*time = clock->getElapsedTime();

	// Restarts the clock
	clock->restart();

	// Updates the world
	world->Step(time->asSeconds(), 6, 2);
}

/// <summary>
/// Displays the position of the target and the player.
/// </summary>
/// <param name="targetPos">The target vector.</param>
/// <param name="playerPos">The player vector.</param>
void display(b2Vec2 targetPos, b2Vec2 playerPos)
{
	// Display the positions
	printf("Target %.2f, %.2f --> Snake %.2f, %.2f\n", targetPos.x, targetPos.y, playerPos.x, playerPos.y);
}

/// <summary>
/// Reads the key presses and applies the forces to the player to move.
/// </summary>
/// <param name="body">The player to move.</param>
void applyForces(b2Body* body)
{
	// Read the input
	char input = _getch();

	// Use ApplyForceToCenter to add the force to the snake
	switch (input)
	{
		case 'w':
		case 'W':
			body->SetLinearVelocity(b2Vec2(0.0f, 10.0f)); // 'Jumps' up
			break;

		case 'a':
		case 'A':
			body->SetLinearVelocity(b2Vec2(-0.4f, 0.0f)); // Moves left
			break;

		case 's':
		case 'S':
			body->SetLinearVelocity(b2Vec2(0.0f, -10.0f)); // Moves down
			break;

		case 'd':
		case 'D':
			body->SetLinearVelocity(b2Vec2(0.4f, 0.0f)); // Moves right
			break;

		case 27: // escape
			body->SetAwake(false); // Sets the snake to sleep
			break;

		default:
			break;
	}
}

/// <summary>
/// Moves the target to a new location.
/// </summary>
/// <param name="target">The target vector.</param>
void moveTarget(b2Vec2* target)
{
	// Location in the range of -5.0 -> 5.0 in X and -5.0 -> 5.0 in Y
	float x = 10.0f * ((float)rand() / RAND_MAX) - 5.0f;
	float y = 10.0f * ((float)rand() / RAND_MAX) - 5.0f;

	// Move the target
	target->Set(x, y);
}