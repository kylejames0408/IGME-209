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
/// Displays the position of the target and the player. [DEBUG ONLY] Reports to console.
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
	// Add the force to the snake dependent on keyboard press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, 10.0f)); // 'Jumps' up

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		body->SetLinearVelocity(b2Vec2(-1.0f, body->GetLinearVelocity().y)); // Moves left

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, -10.0f)); // Moves down

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		body->SetLinearVelocity(b2Vec2(1.0f, body->GetLinearVelocity().y)); // Moves right

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		body->SetActive(false); // Sets the snake to sleep
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