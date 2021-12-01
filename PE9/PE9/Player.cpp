#include "Player.h"


Player::Player() {
	name = "Unknown";
	strength = 10;
	speed = 10;
	wisdom = 10;
}

Player::Player(const char* _name, int _strength, int _speed, int _wisdom)
{
	name = _name;
	strength = _strength;
	speed = _speed;
	wisdom = _wisdom;
}

void Player::PrintPlayer()
{
	cout << "Player Name: " << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Speed: " << speed << endl;
	cout << "Wisdom: " << wisdom << endl<<endl;
}
