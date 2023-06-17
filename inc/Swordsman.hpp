#pragma once 
#include "Unit.hpp"

class Swordsman: public Unit{
    private:
        static constexpr int _default_stamina = 60;
        static constexpr int _speed = 2;
        static constexpr int _cost = 250;
        static constexpr int _attack_range = 1;
        static constexpr int _building_time = 3;
    public:
        Swordsman(int _stamina);
        Swordsman();
        ~Swordsman();
};