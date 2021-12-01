#include <iostream>
#include <fstream>

using namespace std;

//IGME 209 PE16 File IO
//Samar Karnani

int main()
{
	//Checks if text.txt exists otherwise creates it
	ofstream outFile = ofstream("text.txt");
	if (outFile.is_open()) {
		//writes text to file
		outFile << "This is the first line of text" << endl;
		outFile << "This is the second line of text" << endl;
		outFile << "This is the last line of text" << endl;
	}
	outFile.close();	//closes file

	//Checks for file
	ifstream inFile = ifstream("text.txt", ios::binary);
	string fileAsString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());	//copies file contents to string
	inFile.close();

	cout << fileAsString << endl;

}
