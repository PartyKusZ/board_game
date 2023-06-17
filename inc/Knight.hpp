#pragma once 
#include "Unit.hpp"

class Knight: public Unit{
    private:
        static constexpr int _default_stamina = 70;
        static constexpr int _speed = 5;
        static constexpr int _cost = 400;
        static constexpr int _attack_range = 1;
        static constexpr int _building_time = 5;
    public:
        Knight(int _stamina);
        Knight();
        ~Knight();
};