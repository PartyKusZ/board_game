#pragma once 
#include "Unit.hpp"

/**
 * @brief  Class representing an Catapult unit
 * 
 */

class Catapult: public Unit{
    public:
        static constexpr int _default_stamina = 50;//!< default stamina
        static constexpr int _speed = 2;           //!< default speed
        static constexpr int _cost = 800;          //!< default cost
        static constexpr int _attack_range = 7;    //!< default attack range
        static constexpr int _building_time = 6;   //!< default building time

        static constexpr Type_of_unit _unit = Type_of_unit::CATAPULT; //!< unit type

   
    /*Method descriptions can be found in the corresponding source file */

        Catapult(int _stamina, int _id, Ownership _ownership);
        Catapult(int _id, Ownership _ownership);
        ~Catapult();
};