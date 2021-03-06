// PE7_Pointers_Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//IGME 209 PE7
//Samar Karnani

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	//The code crashes in debug mode because the code is trying to delete fakemonster after deleting pOne
	//Since they point to the same address the code does not have access to it

	//Printing out object addresses
	cout << "Address of Boss: " << boss << endl;
	cout << "Address of Player: " << pOne << endl;
	cout << "Address of FakeMonster: " << fakeMonster << endl;

	//Changing positional data
	boss->xPos = 20;
	boss->yPos = 20;
	pOne->xPos = 10;
	pOne->yPos = 10;
	fakeMonster->xPos = 15;
	fakeMonster->yPos = 25;

	//printing out positions
	cout << "\nBoss position --> ";
	boss->PrintPos();
	cout << "\nPlayer position --> ";
	pOne->PrintPos();
	cout << "\nfakeMonster position --> ";
	fakeMonster->PrintPos();

	//When the base classes are used the, deconstructor for the player isnt being used since the object isn't a player object
	//Therefore "player dtor" isnt printed out 
	delete boss;
	delete pOne;
	//delete fakeMonster;

	return 0;
}

