#pragma once
#include "Unit.hpp"

class Archer: public Unit{
    public:
        Archer(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);
        ~Archer();
};