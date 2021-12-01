#pragma once
#include "Player.h"
class Fighter :
    public Player
{
private:
    int weaponSkill;

public:
    Fighter();
    Fighter(const char* _name, int _weaponSkill, int _strength, int _speed, int _wisdom);
    ~Fighter();

    void PrintFighter();
};

