#pragma once 
#include "Unit.hpp"

class Pikeman: public Unit{
    private:
        static constexpr int _default_stamina = 50;
        static constexpr int _speed = 2;
        static constexpr int _cost = 200;
        static constexpr int _attack_range = 2;
        static constexpr int _building_time = 3;
    public:
        Pikeman(int _stamina);
        Pikeman();
        ~Pikeman();
};