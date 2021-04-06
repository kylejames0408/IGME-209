// Inclusions
#include <iostream>

// 11
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/// <summary>
/// Create a small windowed application using SFML that will allow us to draw some primitive shapes to the windows application.
/// </summary>
/// <returns>Console Application</returns>
int main()
{
    // Create the Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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
        }

        // Clear the window with yellow color
        window.clear(sf::Color(255, 220, 104));

        // Draw everything here...
        // window.draw(...);
        
        // Create the top of the balloon -- shape 1
        sf::CircleShape balloonTop(100);                // Create Circle with radius 100
        balloonTop.setFillColor(sf::Color(197, 28, 0)); // Fill Circle with Red
        balloonTop.setOutlineThickness(10);             // Set the outline thickness to 10
        balloonTop.setOutlineColor(sf::Color::Black);   // Set the outline color to black
        balloonTop.setPosition(300, 10);                // Set the Circle's position
        window.draw(balloonTop);                        // Draw the shape

        // Create the bottom of the balloon -- shape 2
        sf::ConvexShape balloonTail;                    // Create a ConvexShape
        balloonTail.setPointCount(4);                   // Give it 4 vertices
        balloonTail.setPoint(0, sf::Vector2f(390, 220));// Set Point position
        balloonTail.setPoint(1, sf::Vector2f(410, 220));
        balloonTail.setPoint(2, sf::Vector2f(420, 230));
        balloonTail.setPoint(3, sf::Vector2f(380, 230));
        balloonTail.setFillColor(sf::Color(197, 28, 0));
        balloonTail.setOutlineThickness(10);
        balloonTail.setOutlineColor(sf::Color::Black);
        window.draw(balloonTail);

        // Create the string -- shape 3
        sf::RectangleShape string(sf::Vector2f(200, 10));   // Create a line with length 200 and width 10
        string.setPosition(405, 230);
        string.rotate(90);                                  // Rotate the line
        string.setFillColor(sf::Color::Black);
        window.draw(string);

        // Create the left shine -- shape 4
        sf::RectangleShape lShine(sf::Vector2f(100, 5));
        lShine.setPosition(340, 45);
        lShine.rotate(100);
        lShine.setFillColor(sf::Color::White);
        window.draw(lShine);

        // Create the right shine -- shape 5
        sf::RectangleShape rShine(sf::Vector2f(50, 5));
        rShine.setPosition(465, 35);
        rShine.rotate(65);
        rShine.setFillColor(sf::Color::White);
        window.draw(rShine);

        // End the current frame
        window.display();
    }
}