#include <iostream>
#include <time.h>
using namespace std;

//IGME 209 PE6- Debugging
//Samar Karnani

void GenerateRandom(short);	//generates a series of random numbers
char* reverseString(char inputString[]);

char input[128] = "";

int main()
{
	GenerateRandom(25);

	cout << "\n\nPlease enter a string: ";
	cin >> input;
	cout << "\nThe reverse of the string is: " << reverseString(input) << endl;
}

void GenerateRandom(short numberOfRandoms) {
	srand(time(NULL));

	for (short i = 0; i < numberOfRandoms; i++) {
		int random = rand();
		cout << "Iteration number " << i + 1 << ": " << random <<endl;
	}
}

char* reverseString(char inputString[]) {
	char newString[256] = "";
	int length = strlen(inputString);
	for (int i = 0; i < length; i++) {
		char c = inputString[i];
		newString[length - i /*-1*/] = c;	//The character positions in the new string will start with index 1 otherwise
										//Therefore the copy will end before hitting a character 
	}
	cout << newString[0] << endl;
	strcpy_s(inputString, 128, newString);
	return inputString;
}
