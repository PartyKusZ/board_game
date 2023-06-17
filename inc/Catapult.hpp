#pragma once 
#include "Unit.hpp"

class Catapult: public Unit{
    public:
        Catapult(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);
        ~Catapult();
};