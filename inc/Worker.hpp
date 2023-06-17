#pragma once 
#include "Unit.hpp"

class Worker: public Unit{
    private:
        static constexpr int _default_stamina = 20;
        static constexpr int _speed = 2;
        static constexpr int _cost = 100;
        static constexpr int _attack_range = 1;
        static constexpr int _building_time = 2;
    public:
        Worker(int _stamina);
        Worker();
        ~Worker();
};