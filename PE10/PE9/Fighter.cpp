#include "Fighter.h"

/// <summary>
/// Fighter default constructor
/// </summary>
Fighter::Fighter():Player("Fighter",10,10,10)
{
	weaponSkill = 10;
}

/// <summary>
/// Fighter Param Constructor
/// </summary>
/// <param name="_name">Fighter name</param>
/// <param name="_weaponSkill">Fighter weapon skill</param>
/// <param name="_strength">Fighter strength</param>
/// <param name="_speed">Fighter speed</param>
/// <param name="_wisdom">Fighter wisdom</param>
Fighter::Fighter(const char* _name, int _weaponSkill, int _strength, int _speed, int _wisdom) : Player(_name, _strength, _speed, _wisdom)
{
	weaponSkill = _weaponSkill;
}

/// <summary>
/// Fighter destructor
/// </summary>
Fighter::~Fighter()
{
}

/// <summary>
/// Prints fighter data
/// </summary>
void Fighter::PrintFighter()
{
	PrintPlayer();
	cout << "Weapon Skill: " << weaponSkill << endl;
}
