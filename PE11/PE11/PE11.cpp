#include <iostream>
#include "Item.h"
#include "Axe.h"
#include "Arrow.h"
#include "Sword.h"
#include "Spear.h"
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include<cstdlib>
#include<crtdbg.h>

using namespace std;

//IGME 209 PE11
//Samar Karnani

int main()
{
	//Create pointers for items
	Item* item = new Item();
	Axe* axe = new Axe();
	Arrow* arrow = new Arrow();
	Sword* sword = new Sword();
	Spear* spear = new Spear();

	//create vector
	vector<Item*> itemList = vector<Item*>();
	itemList.push_back(item);
	itemList.push_back(axe);
	itemList.push_back(arrow);
	itemList.push_back(spear);
	itemList.push_back(sword);

	for (int i = 0; i < itemList.size(); i++) {
		itemList[i]->Print();
	}

	//delete items
	delete item;
	delete axe;
	delete arrow;
	delete sword;
	delete spear;

	//get rid of dangling pointers
	item = nullptr;
	axe = nullptr;
	arrow = nullptr;
	spear = nullptr;
	sword = nullptr;

	_CrtDumpMemoryLeaks();
}