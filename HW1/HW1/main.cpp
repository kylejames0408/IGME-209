// Inclusions
#include <iostream>
#include <cstring>
#include "hangman.h"

// Usings
using namespace std;

// Global Variables
bool guessed = false;
int lettersRemaining;

/// <summary>
/// Work with arrays and Cstrings to make Hangman.
/// </summary>
/// <returns>Runs the Console Application.</returns>
int main()
{
	// Create C-style strings, word-to-be-guessed and guessed letters.
	char word[] = "fallout";
	char guesses[27] = "";

	// Variables
	short remainingGuesses = 7;

	// Introduce the game to the user
	cout << "Let's play hangman!\nYour word has " << strlen(word) << " letters in it.\n" << endl;

	// While the user hasn't guessed the word and there are guesses remaining
	while (remainingGuesses > 0 && !guessed)
	{
		// Get the user's input
		char input;
		cout << "What letter do you guess next? ";
		cin >> input;

		// Make the input lowercase
		input = tolower(input);

		// Concatenate the guess to the guesses
		strncat_s(guesses, &input, 1);

		// If the input is not in the word
		if (!strchr(word, input))
		{
			// Reduce the remaining guesses
			remainingGuesses -= 1;
		}

		// Report the user's guess
		cout << "Guess: " << input << endl;

		// Report the status of the game
		showGallows(remainingGuesses);
		showSolveDisplay(word, guesses);
		cout << endl << lettersRemaining << " letters left to guess" << endl;
	}

	// If the user guessed it
	if (guessed)
	{
		// Report that they won
		cout << "\nYou win!!" << endl;
	}
	else// The user lost
	{
		// Report that they lost and what the word was
		cout << "\n You lose. The word was: " << word << endl;
	}
}