#pragma once 
#include "Unit.hpp"

class Catapult: public Unit{
    private:
        static constexpr int _default_stamina = 50;
        static constexpr int _speed = 2;
        static constexpr int _cost = 800;
        static constexpr int _attack_range = 7;
        static constexpr int _building_time = 6;
    public:
        Catapult(int _stamina);
        Catapult();
        ~Catapult();
};