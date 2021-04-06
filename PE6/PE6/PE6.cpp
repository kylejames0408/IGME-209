// Inclusions
#include <iostream>
#include <time.h>

// Prepare namespace
using namespace std;

// Declare functions
/// <summary>
/// Generates a specified amount of random numbers.
/// </summary>
/// <param name="numberOfRandoms">The number of random numbers to generate.</param>
void generateRandom(int numberOfRandoms);

/// <summary>
/// Reverses a CString.
/// </summary>
/// <param name="inputString">The CString to reverse.</param>
/// <returns>The reversed CString.</returns>
char* reverseString(char inputString[]);

/// <summary>
/// The main function of the console application.
/// </summary>
/// <returns>Console Application.</returns>
int main()
{
    // Part 1
    // Generate 25 random numbers
    generateRandom(25);

    // Part 2
    // Temporary Variables
    char input[128];

    // Get the user's input
    cout << "Please enter a string: ";
    cin.getline(input, 127);
    cout << endl;
    
    // Reverse the string and print it to the console
    cout << "Reversed String: " << reverseString(input) << endl;
}

// Functions
/// <summary>
/// Generates a specified amount of random numbers.
/// </summary>
/// <param name="numberOfRandoms">The number of random numbers to generate.</param>
void generateRandom(int numberOfRandoms)
{
    // 4 Seed Random - give it the current time to generate "random" numbers
    srand(time(NULL));

    // 5 Loop to generate random numbers
    for (int i = 0; i < numberOfRandoms; i++)
    {
        // Loop count
        int loopCount = i + 1;

        // Generate random number
        int randomNumber = rand();

        // Print out the iteration count and the value of the random
        cout << "The " << loopCount << " random number is " << randomNumber << "." << endl;
    }
}
// PART 1 - OUTPUT
//  The output file is in PE6\pt1.6.txt, but is also copied here.
//  i		        19	    int
//  loopCount	    20	    int
//  numberOfRandoms	25	    int
//  randomNumber	32078	int

/// <summary>
/// Reverses a CString.
/// </summary>
/// <param name="inputString">The CString to reverse.</param>
/// <returns>The reversed CString.</returns>
char* reverseString(char inputString[])
{
    char newString[256] = "";
    int length = strlen(inputString);
    for (int i = 0; i < length; i++)
    {
        char c = inputString[i];
        newString[length - i] = c;
    }
    strcpy_s(inputString, 128, newString);
    return inputString;
}

// PART 2 - WHY IT DOESN'T WORK:
//  The reverseString function doesn't work because the characters are being placed
//  in the wrong places. To fix the issue, line 81, which states newString[length - i] = c;
//  should be replaced with newString[length - (i + 1)] = c; or any algebraic equivalent
//  resulting in another -1. Without doing so, the beginning of the inputString is replaced
//  with a \0 end-string character, preventing the reverse string from printing.
//  Fixing that line will also ensure that the first character is not an end-string line,
//  allowing the reverse string to print. 