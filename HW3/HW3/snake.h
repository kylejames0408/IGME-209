#pragma once
// Box2D Inclusions
#include <Box2D/Box2D.h>

// SFML Inclusions
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/// <summary>
/// Update the physics world.
/// </summary>
/// <param name="clock">The Clock to track time.</param>
/// <param name="time">The Time change since last tick.</param>
/// <param name="world">The phsysics world.</param>
void update(sf::Clock* clock, sf::Time* time, b2World* world);

/// <summary>
/// Displays the position of the target and the player.
/// </summary>
/// <param name="targetPos">The target vector.</param>
/// <param name="playerPos">The player vector.</param>
void display(b2Vec2 targetPos, b2Vec2 playerPos);

/// <summary>
/// Reads the key presses and applies the forces to the player to move.
/// </summary>
/// <param name="body">The player to move.</param>
void applyForces(b2Body* body);

/// <summary>
/// Moves the target to a new location.
/// </summary>
/// <param name="target">The target vector.</param>
void moveTarget(b2Vec2* target);