#pragma once 
#include "Unit.hpp"

class Pikeman: public Unit{
    public:
        Pikeman(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);
        ~Pikeman();
};