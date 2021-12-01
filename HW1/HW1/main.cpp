#include "hangman.h"
#include <iostream>
#include <string.h>
using namespace std;

//IGME 209 DSA1 HW1- Hangman
//Samar Karnani

int main()
{
	char word[13] = "cheeseburger";
	char correctGuesses[32]="";
	char wrongGuesses[32]="";
	char input[99];
	int gameState = 0;
	const int MAX_WRONG_GUESSES = 7;

	cout << "Welcome to Hangman... or the beginner's c++ version of it at least!\n" << endl;
	cout << "If you don't know how this game works, don't worry. It's quite simple.\nYou have to guess the letters in the word. The correct guesses will be displayed.\n" << endl;
	cout << "Just remember that you don't have unlimited wrong attempts!\n\n" << endl;

	cout << "Are you ready to play? (Y/N)" << endl;
	cin.getline(input,2);
	input[0] = tolower(input[0]);
	if (input[0] != 'y') {
		cout << "Alright... See ya next time!";
		exit(0);
	}

	while (gameState == 0 && strlen(wrongGuesses)<MAX_WRONG_GUESSES) {
		cout << "Let's play Hangman" << endl;
		cout << "Your word has " << sizeof(word) << " letters in it\n" << endl;
		cout << "What letter do you guess next?";
		cin >> input;
		input[0] = tolower(input[0]);
		cout << "\nGuess: " << input << endl;

		if (strchr(word, input[0]) == NULL) {
			strcat_s(wrongGuesses, input);
		}
		else
		{
			strcat_s(correctGuesses, input);
		}

		showGallows(strlen(wrongGuesses));

		char totalGuesses[64];
		strcpy_s(totalGuesses, wrongGuesses);
		strcat_s(totalGuesses, correctGuesses);
		showSolveDisplay(word, totalGuesses);

		gameState = 1;
		for (int i = 0; i < strlen(word); i++) {
			if (!strchr(correctGuesses, word[i])) {
				gameState = 0;
			}
		}
	}

	if (strlen(wrongGuesses) >= MAX_WRONG_GUESSES) {
		cout << "\n\nOops it looks like you ran out of guesses." << endl;
		cout << "Better luck next time!"<<endl;
		exit(0);
	}

	cout << "\n\nCongratulations! You guessed the word!" << endl;
	cout << "Come back and play again.\n";
}