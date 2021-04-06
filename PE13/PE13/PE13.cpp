// Inclusions
#include <iostream>

// Using Statements
using namespace std;

// Method Declarations
/// <summary>
/// A method that uses iteration to find the total number of hands in a row with N seats.
/// </summary>
/// <param name="seats">The number of seats in a row.</param>
/// <returns>The number of hands in a row.</returns>
unsigned int iterationHands(int seats);

/// <summary>
/// A method that uses recursion to find the total number of hands in a row with N seats.
/// </summary>
/// <param name="seats">The number of seats in a row.</param>
/// <returns>The number of hands in a row.</returns>
unsigned int recursiveHands(int seats);

/// <summary>
/// A method that uses formula to find the total number of hands in a row with N seats.
/// </summary>
/// <param name="seats">The number of seats in a row.</param>
/// <returns>The number of hands in a row.</returns>
unsigned int formulaHands(int seats);

// Methods
/// <summary>
/// The main method of the program.
/// </summary>
/// <returns>0 - The Console Application</returns>
int main()
{
    // 1 - By the year 3000, several thousand species in the galaxy are united under the Democratic Order of Planets. A group of Neptunians and Omicronians visit a human movie theater.
    // Neptunians have four hands and can only occupy even numbered seats (e.g.  2, 4, 6) while Omicronians have three hands and can only occupy odd numbered seats (e.g.  1, 3, 5).
    // Thus, if a row had three seats the total number of hands in that row would be 10.
    cout << "Hands in Rows at a Movie Theater: The Year 3000" << endl;
    cout << "Row 1 - Iteration: " << iterationHands(10) << endl;
    cout << "Row 2 - Recursion: " << recursiveHands(10) << endl;
    cout << "Row 3 - Formula:   " << formulaHands(10) << endl;
}

/// <summary>
/// A method that uses iteration to find the total number of hands in a row with N seats.
/// </summary>
/// <param name="seats">The number of seats in a row.</param>
/// <returns>The number of hands in a row.</returns>
unsigned int iterationHands(int seats)
{
    // The sum of hands
    unsigned int sum = 0;

    // Iterate through the seats
    while (seats > 0)
    {
        // If the seat number is even
        if (seats % 2 == 0)
            sum += 4;       // Add four hands
        else // If the seat number is odd
            sum += 3;       // Add three hands

        // Go to the next seat
        seats--;
    }

    // Return the sum of hands
    return sum;
}

/// <summary>
/// A method that uses recursion to find the total number of hands in a row with N seats.
/// </summary>
/// <param name="seats">The number of seats in a row.</param>
/// <returns>The number of hands in a row.</returns>
unsigned int recursiveHands(int seats)
{
    // If there are no seats
    if (seats <= 0)
        return 0;   // Return 0 hands

    // The sum of hands
    unsigned int sum;

    // If the seat number is even
    if (seats % 2 == 0)
        sum = 4;       // Add four hands
    else // If the seat number is odd
        sum = 3;       // Add three hands

    // Recursive call to the function
    return sum + recursiveHands(seats - 1);
}

/// <summary>
/// A method that uses formula to find the total number of hands in a row with N seats.
/// </summary>
/// <param name="seats">The number of seats in a row.</param>
/// <returns>The number of hands in a row.</returns>
unsigned int formulaHands(int seats)
{
    // Return the number of hands using a formula
    // Half of the seats (rounded up if necessary) times three hands
    // Plus
    // Half of the seats (integer division) times four hands
    return unsigned int(ceil(seats / 2.0) * 3 + (seats / 2) * 4.0);
}