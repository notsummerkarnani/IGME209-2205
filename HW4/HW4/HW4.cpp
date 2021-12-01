#include <iostream>
#include "Stack.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//Samar Karnani
//IGME 209 HW4

using namespace std;

void Wrapper();

int main()
{
    Wrapper();
    _CrtDumpMemoryLeaks();
}

void Wrapper()
{
    //Create Stacks
    Stack<int>* ints = new Stack<int>();
    Stack<char>* chars = new Stack<char>();
    Stack<float>* floats = new Stack<float>();

    //Populate Stacks
    for (int i = 0; i < 5; i++) {
        ints->Push(i);
        floats->Push((i * 867) % 255);
        chars->Push(i + 45);
    }

    cout << "Printing contents of ints:" << endl;
    ints->Print();
    cout << "\nPrinting contents of chars:" << endl;
    chars->Print();
    cout << "\nPrinting contents of floats:" << endl;
    floats->Print();

    cout << endl << endl << "Popping items..." << endl;
    for (int i = 0; i < 3; i++) {
        ints->Pop();
        floats->Pop();
        chars->Pop();
    }

    cout << "\nPrinting contents of ints:" << endl;
    ints->Print();
    cout << "\nPrinting contents of chars:" << endl;
    chars->Print();
    cout << "\nPrinting contents of floats:" << endl;
    floats->Print();

    delete floats;
    delete chars;

    Stack<int>* ints2 = new Stack<int>(*ints);  //copy constructor
    Stack<int>* ints3 = (ints);                 //copy assignment

    cout << "\nPrinting contents of ints2:" << endl;
    ints2->Print();
    cout << "\nPopping an item from ints2 ..." << endl;
    ints2->Pop();
    cout << "\nPrinting contents of ints2:" << endl;
    ints2->Print();
    cout << "\nPushing an item to ints3" << endl;
    ints3->Push(4);
    cout << "\nPrinting contents of ints3:" << endl;
    ints3->Print();

    delete ints2;
    delete ints3;
}
