#pragma once 
#include "Unit.hpp"

class Knight: public Unit{
    public:
        Knight(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);
        ~Knight();
};