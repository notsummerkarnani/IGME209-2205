using namespace std;
#include <iostream>
#include <cstring>

//IGME 209 PE4 - Strings
//Samar Karnani

int main()
{

    char word[64] = "supercalifragilistic";
    cout << "Size of 'supercalifragilistic': " << strlen(word) << endl;

    char secondWord[32] = "expialidocious";
    strcat_s(word, secondWord);
    cout << "Combined result: " << word << endl;

    int numTimes = 0;
    char searchLetter = 'i';
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == searchLetter) {
            numTimes++;
        }
    }
    cout << "\n\nNumber of times the letter  is present: " << numTimes << endl << endl;


    //test
    char a[10] = "aaa";
    cout << strlen(a);
}
