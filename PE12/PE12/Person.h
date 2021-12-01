#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Person
{
private:
	string name;
	int health;
	vector<string> inventory;

public:
	//Default Constructor for Person
	Person();
	//Param Constructor for Person
	Person(string _name, int _health);
	//Destructor for Person
	~Person();
	
	//Adds string item to the Person's inventory
	void Addinventory(string _item);
	
	//Prints the Person's name, health and inventory data to the console
	void PrintInfo();

};

