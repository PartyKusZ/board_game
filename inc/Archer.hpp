#pragma once
#include "Unit.hpp"

class Archer: public Unit{
    private:
        static constexpr int _default_stamina = 40;
        static constexpr int _speed = 2;
        static constexpr int _cost = 250;
        static constexpr int _attack_range = 5;
        static constexpr int _building_time = 3;

    public:
        Archer(int _stamina);
        Archer();
        ~Archer();
};