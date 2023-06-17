#pragma once 
#include "Unit.hpp"

/**
 * @brief  Class representing an Swordsman unit
 * 
 */


class Swordsman: public Unit{
    private:
        static constexpr int _default_stamina = 60; //!< default stamina
        static constexpr int _speed = 2;            //!< default speed
        static constexpr int _cost = 250;           //!< default cost
        static constexpr int _attack_range = 1;     //!< default attack range
        static constexpr int _building_time = 3;    //!< default building time
    public:
    /*Method descriptions can be found in the corresponding source file */

        Swordsman(int _stamina);
        Swordsman();
        ~Swordsman();
};