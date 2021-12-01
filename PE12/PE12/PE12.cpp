#include <iostream>
#include <memory>
#include "Person.h"
#include "SmartPointer.h"
#define _CRTDBG_MAP_ALLOC
#include<cstdlib>
#include<crtdbg.h>
using namespace std;

//IGME 209 PE12
//Samar Karnani

void Wrapper();

int main()
{
	Wrapper();
	_CrtDumpMemoryLeaks();
}

void Wrapper() {
	//Creates a normal pointer for a new Person
	Person *person1 = new Person("Blitz", 1000);
	person1->Addinventory("shield");

	//creates a smartpointer for a new person
	SmartPointer<Person> smartPerson(new Person("Caviera", 100));
	smartPerson.operator->()->Addinventory("Silencer");

	//prints out player daya
	person1->PrintInfo();
	smartPerson.operator->()->PrintInfo();

	//deletes the pointer for person1 (normal pointer)
	delete person1;
	person1 = nullptr;
}