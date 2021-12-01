#include "Player.h"
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include<cstdlib>
#include<crtdbg.h>

//IGME 209 PE9
//Samar Karnani

int main()
{
    Player player1 = Player();
    Player player2 = Player("Player2", 11, 11, 11);
    Player* player3 = new Player();
    Player* player4 = new Player("Player4", 12, 12, 12);

    player1.PrintPlayer();
    player2.PrintPlayer();
    player3->PrintPlayer();
    player4->PrintPlayer();

    delete player3;
    delete player4;

    _CrtDumpMemoryLeaks();
}
