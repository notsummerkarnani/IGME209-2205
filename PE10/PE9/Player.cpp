#include "Player.h"

/// <summary>
/// Player Default Constructor
/// </summary>
Player::Player() {
	name = "Unknown";
	strength = 10;
	speed = 10;
	wisdom = 10;
}

/// <summary>
/// Player Param constructor
/// </summary>
/// <param name="_name">player name</param>
/// <param name="_strength">Player strength</param>
/// <param name="_speed">Player speed</param>
/// <param name="_wisdom">Player wisom</param>
Player::Player(const char* _name, int _strength, int _speed, int _wisdom)
{
	name = _name;
	strength = _strength;
	speed = _speed;
	wisdom = _wisdom;
}

/// <summary>
/// Prints Player data
/// </summary>
void Player::PrintPlayer()
{
	cout << "\nPlayer Name: " << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Speed: " << speed << endl;
	cout << "Wisdom: " << wisdom << endl;
}
