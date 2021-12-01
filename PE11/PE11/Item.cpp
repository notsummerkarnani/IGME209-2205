#include "Item.h"

Item::Item()
{
	name = "Item";
	damage = 10;
	speed = 10;
}

Item::~Item()
{
}

void Item::Print()
{
	cout << "\nItem name: " << name << endl;
	cout << "Damage: " << damage << endl;
	cout << "Speed: " << speed << endl;
}
