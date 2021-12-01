#pragma once
#include <iostream>
using namespace std;

struct Item
{
protected:
	string name;
	int speed;
	int damage;

public:
	Item();
	~Item();

	void Print();
};

