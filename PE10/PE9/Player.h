#pragma once

#include <iostream>
using namespace std;

class Player
{
private:
	const char* name;
	int strength;
	int speed;
	int wisdom;

public:
	Player();
	Player(const char* _name, 
		int _strength, 
		int _speed, 
		int _wisdom);
	void PrintPlayer();
};

