#pragma once 
#include "Unit.hpp"

class Base: public Unit{
    private:
        static constexpr int _default_stamina = 200;
        static constexpr int _speed = 0;
        static constexpr int _cost = 0;
        static constexpr int _attack_range = 0;
        static constexpr int _building_time = 0;
    public:
        Base();
        ~Base();
};