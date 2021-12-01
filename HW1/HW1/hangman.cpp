using namespace std;
#include <iostream>

/// <summary>
/// Using the parameter it prints out the Gallows art
/// </summary>
/// <param name="wrongGuesses">Number of wrong guesses so far</param>
void showGallows(int wrongGuesses) {
	switch (wrongGuesses) {

	case 0:
		cout << "\t______" << endl;
		cout << "\t|\n\t|\n\t|\n\t|\n\t|\n\t|" << endl;
		break;

	case 1:
		cout << "\t______" << endl;
		cout << "\t|  |\n\t|\n\t|\n\t|\n\t|\n\t|" << endl;
		break;

	case 2:
		cout << "\t______" << endl;
		cout << "\t|  |\n\t|  O\n\t|\n\t|\n\t|\n\t|" << endl;
		break;
	case 3:
		cout << "\t______" << endl;
		cout << "\t|  |\n\t|  O\n\t|  |\n\t|\n\t|\n\t|" << endl;
		break;

	case 4:
		cout << "\t______" << endl;
		cout << "\t|  |\n\t|  O\n\t| /|\n\t|\n\t|\n\t|" << endl;
		break;

	case 5:
		cout << "\t______" << endl;
		cout << "\t|  |\n\t|  O\n\t| /|\\ \n\t|\n\t|\n\t|" << endl;
		break;
	case 6:
		cout << "\t______" << endl;
		cout << "\t|  |\n\t|  O\n\t| /|\\ \n\t|  /\n\t|\n\t|" << endl;
		break;

	case 7:
		cout << "\t______" << endl;
		cout << "\t|  |\n\t|  O\n\t| /|\\ \n\t|  /\\ \n\t|\n\t|" << endl;
		break;
	}
}

/// <summary>
/// Displays the wrong guesses to the user
/// Shows the word that needs to be solved with the correct letters displayed
/// </summary>
/// <param name="word">Word to be solved</param>
/// <param name="guesses">Guesses made by user</param>
void showSolveDisplay(char word[], char guesses[]) {
	cout << "\nWrong guesses: ";
	for (int i = 0; i < strlen(guesses); i++) {
		if (strchr(word, guesses[i]) == NULL) {
			cout << guesses[i];
		}
	}
	cout << "\nWord to solve: ";
	for (int i = 0; i < strlen(word); i++) {
		if (strchr(guesses, word[i]) == NULL) {
			cout << '_';
		}
		else
		{
			cout << word[i];
		}
	}
	cout << "\n\n";
}

