#pragma once 
#include "Unit.hpp"

/**
 * @brief  Class representing an Ram unit
 * 
 */


class Ram: public Unit{
    private:
        static constexpr int _default_stamina = 90; //!< default stamina
        static constexpr int _speed = 2;            //!< default speed
        static constexpr int _cost = 500;           //!< default cost
        static constexpr int _attack_range = 1;     //!< default attack range
        static constexpr int _building_time = 4;    //!< default building time
        static constexpr Type_of_unit _unit = Type_of_unit::RAM; //!< unit type

    public:
    /*Method descriptions can be found in the corresponding source file */

        Ram(int _stamina, Ownership _ownership);
        Ram(Ownership _ownership);
        ~Ram();
};