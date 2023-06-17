#pragma once 
#include "Unit.hpp"

class Worker: public Unit{
    public:
        Worker(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);
        ~Worker();
};