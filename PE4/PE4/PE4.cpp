// Inclusions
#include <iostream> // Allows writing to console
#include <cstring>  // Adds C String functionality

// Usings
using namespace std;// Allows bypass of std::

/// <summary>
/// Exercise the basic string manipulation functions in C++
/// </summary>
/// <returns>Console Application</returns>
int main()
{
    // 2 Define a C String  "supercalifragilistic"
    char supercalifragilistic[35] = "supercalifragilistic";
    
    // 3 Find the length of the string; print the result to the console
    cout << "Length of " << supercalifragilistic << ": " << strlen(supercalifragilistic) << " characters" << endl;

    // 4 Define a 2nd C string "expialidocious," and add it to the end of the first string; print out the combined result
    char expialidocious[] = "expialidocious";       // Define "expialidocious"
    cout << "The combination of the words " << supercalifragilistic << " and " << expialidocious << " result in: ";

    strcat_s(supercalifragilistic, expialidocious); // Add it to the end of the first string
    cout << supercalifragilistic << endl;           // Print out the combined result

    // 5 Find how many time the character 'i' occurs in the combined string;
    //   print the result to the console (use a loop to do this).
    //     a. As with most solutions, there are multiple ways of doing this. We can discuss why you might use one over the other.
    short count = 0;
    for (unsigned short i = 0; i < strlen(supercalifragilistic); i++)   // Loop through the length of the word to avoid end characters
    {
        if (supercalifragilistic[i] == 'i')                             // If the character at location is i
        {
            count++;                                                    // Increase count
        }
    }
    cout << "There are " << count << " i's in the phrase " << supercalifragilistic << endl; // Print the result to the console
}