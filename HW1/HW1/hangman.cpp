// Inclusions
#include <iostream>
#include <cstring>
#include "hangman.h"

// Usings
using namespace std;

/// <summary>
/// Shows the ASCII art gallows.
/// </summary>
/// <param name="wrongGuessesRemaining">The number of wrong guesses remaining.</param>
void showGallows(int wrongGuessesRemaining)
{
	switch (wrongGuessesRemaining)
	{
		case 6:
			cout << "         _______\n         |   |\n         |\n         |\n         |\n         |\n         |" << endl;
			break;
		case 5:
			cout << "         _______\n         |   |\n         |   o\n         |\n         |\n         |\n         |" << endl;
			break;
		case 4:
			cout << "         _______\n         |   |\n         |   o\n         |   |\n         |\n         |\n         |" << endl;
			break;
		case 3:
			cout << "         _______\n         |   |\n         |   o\n         |  /|\n         |\n         |\n         |" << endl;
			break;
		case 2:
			cout << "         _______\n         |   |\n         |   o\n         |  /|\\\n         |\n         |\n         |" << endl;
			break;
		case 1:
			cout << "         _______\n         |   |\n         |   o\n         |  /|\\\n         |  /\n         |\n         |" << endl;
			break;
		case 0:
			cout << "         _______\n         |   |\n         |   o\n         |  /|\\\n         |  / \\\n         |\n         |" << endl;
			break;
		default:
			cout << "         _______\n         |\n         |\n         |\n         |\n         |\n         |" << endl;
			break;
	}
}

/// <summary>
/// Shows the user's incorrect guesses and correct guesses.
/// </summary>
/// <param name="word">The word to guess.</param>
/// <param name="guesses">The user's guesses.</param>
void showSolveDisplay(char word[], char guesses[])
{
	// Temporary variables
	char hidden[30] = "";	// The hidden word
	char hide = '_';		// The hidden character to append

	// Loop through the length of the word and concatenate the hidden character
	for (unsigned short i = 0; i < strlen(word); i++)
	{
		strncat_s(hidden, &hide, 1);
	}

	// Prepare the output for wrong guesses
	cout << "Wrong guesses: ";

	// Loop through the user's guesses 
	for (unsigned short i = 0; i < strlen(guesses); i++)
	{
		// If the word doesn't contain the character
		if (!strchr(word, guesses[i]))
		{
			// Print the character out
			cout << guesses[i];
		}
		else// If the word contains the character
		{
			// Loop through the word
			for (unsigned short j = 0; j < strlen(word); j++)
			{
				// If the character is the position in the word
				if (guesses[i] == word[j])
				{
					// Replace the hidden character with the character in the word
					hidden[j] = word[j];
				}
			}
		}
	}

	// Print the hidden word
	cout << "\nWord to solve: " << hidden << endl;

	// Prepare the external remaining letters variable
	extern int lettersRemaining;
	lettersRemaining = strlen(word);

	// Loop through the hidden word
	for (unsigned short i = 0; i < strlen(hidden); i++)
	{
		// If the character is not a hidden character
		if (hidden[i] != '_')
		{
			// Reduce the number of letters remaining
			lettersRemaining -= 1;
		}
	}

	// Prepare the externall guessed variable
	extern bool guessed;

	// If there are no letters remaining
	if (lettersRemaining == 0)
	{
		// The word has been guessed
		guessed = true;
	}
}