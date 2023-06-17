#pragma once 
#include "Unit.hpp"

class Ram: public Unit{
    public:
        Ram(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);
        ~Ram();
};