#pragma once 
#include "Unit.hpp"

class Ram: public Unit{
    private:
        static constexpr int _default_stamina = 90;
        static constexpr int _speed = 2;
        static constexpr int _cost = 500;
        static constexpr int _attack_range = 1;
        static constexpr int _building_time = 4;
    public:
        Ram(int _stamina);
        Ram();
        ~Ram();
};