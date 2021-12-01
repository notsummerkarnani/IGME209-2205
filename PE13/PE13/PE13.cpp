#include <iostream>

using namespace std;

//IGME 209 PE13
//Samar Karnani

int Iteration(int _seats);
int Recursion(int _seats);
int Formula(int _seats);

const int NeptunianHands = 4;   //totals hands from 1 Neptunian
const int OmicronionHands = 3;   //totals hands from 1 Omicronion

int main()
{
    int test = 10;

    cout << "Iteration: " << Iteration(test) << endl;
    cout << "Recursion: " << Recursion(test) << endl;
    cout << "Formula: " << Formula(test) << endl;
}

int Iteration(int _seats)
{
    int numHands = 0;

    for (int i = 1; i < _seats+1; i++) {
        if (i % 2 == 0) {
            numHands += NeptunianHands;
        }
        else {
            numHands += OmicronionHands;
        }
    }
    return numHands;
}

int Recursion(int _seats)
{
    if (_seats <= 1) {
        return OmicronionHands;
    }

    if (_seats % 2 == 0) {
        return NeptunianHands + Recursion(_seats-1);
    }
    else{
        return OmicronionHands + Recursion(_seats - 1);
    }

}

int Formula(int _seats)
{
    if (_seats % 2 == 0) {
        return _seats * (NeptunianHands + OmicronionHands)/2;
    }
    else {
        return (_seats - 1)/2 * (NeptunianHands + OmicronionHands) + 3;
    }
}
