#include "Player.h"
#include "Fighter.h"
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include<cstdlib>
#include<crtdbg.h>

//IGME 209 PE10
//Samar Karnani

int main()
{
    //creates 2 fighters
    Fighter* fighter1 = new Fighter();
    Fighter* fighter2 = new Fighter("Bobby", 11, 11, 11, 11);

    //Prints fighter data
    fighter1->PrintFighter();
    fighter2->PrintFighter();

    //deletes fighters and sets pointers to null
    delete fighter1;
    fighter1 = nullptr;
    delete fighter2;
    fighter2 = nullptr;

    _CrtDumpMemoryLeaks();
}
