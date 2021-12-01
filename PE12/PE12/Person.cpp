#include "Person.h"

//Default Constructor for Person
Person::Person()
{
	cout << "Default constructor called" << endl;
	name = "Bobby";
	health = 100;
}

//Param Constructor for Person
Person::Person(string _name, int _health)
{
	cout << "Param constructor called" << endl;
	name = _name;
	health = _health;

}

//Destructor for Person
Person::~Person()
{
	cout << "Destructor called for " << name << endl;
}

//Adds string item to the Person's inventory
void Person::Addinventory(string _item)
{
	inventory.push_back(_item);
}

//Prints the Person's name, health and inventory data to the console
void Person::PrintInfo()
{
	cout << endl << "Player info:" << endl;
	cout << "Name: " << name << endl;
	cout << "Health: " << health << endl;
	cout << "Inventory: ";
	for (int i = 0; i < inventory.size(); i++) {
		cout << inventory[i] << " ";
	}
	cout << endl;
}
