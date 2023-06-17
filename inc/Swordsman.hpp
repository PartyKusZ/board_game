#pragma once 
#include "Unit.hpp"

class Swordsman: public Unit{
    public:
        Swordsman(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);
        ~Swordsman();
};