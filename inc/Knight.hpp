#pragma once 
#include "Unit.hpp"

/**
 * @brief Class representing an Knight unit
 * 
 */
class Knight: public Unit{
    private:
        static constexpr int _default_stamina = 70; //!< default stamina
        static constexpr int _speed = 5;            //!< default speed
        static constexpr int _cost = 400;           //!< default cost
        static constexpr int _attack_range = 1;     //!< default attack range
        static constexpr int _building_time = 5;    //!< default building time
        static constexpr Type_of_unit _unit = Type_of_unit::KNIGHT; //!< unit type
    public:
    /*Method descriptions can be found in the corresponding source file */

        Knight(int _stamina, Ownership _ownership);
        Knight(Ownership _ownership);
        ~Knight();
};