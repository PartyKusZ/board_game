#pragma once
#include "Unit.hpp"

/**
 * @brief  Class representing an Archer unit
 * 
 */

class Archer: public Unit{
    private:
        static constexpr int _default_stamina = 40; //!< default stamina
        static constexpr int _speed = 2;            //!< default speed
        static constexpr int _cost = 250;           //!< default cost
        static constexpr int _attack_range = 5;     //!< default attack range
        static constexpr int _building_time = 3;    //!< default building time

        static constexpr Type_of_unit _unit = Type_of_unit::ARCHER; //!< unit type

    public:
    /*Method descriptions can be found in the corresponding source file */

        Archer(int _stamina, int _id, Ownership _ownership);
        Archer(int _id, Ownership _ownership);
        ~Archer();
};