#pragma once 
#include "Unit.hpp"
/**
 * @brief  Class representing an Base unit
 * 
 */

class Base: public Unit{
    private:
        static constexpr int _default_stamina = 200;//!< default stamina
        static constexpr int _speed = 0;            //!< default speed
        static constexpr int _cost = 0;             //!< default cost
        static constexpr int _attack_range = 0;     //!< default attack range
        static constexpr int _building_time = 0;    //!< default building time

        static constexpr Type_of_unit _unit = Type_of_unit::BASE; //!< unit type
        bool under_construction = false; //!< if true Base builds the unit
        Type_of_unit unit_under_construction; //!< unit under construction

    public:
    /*Method descriptions can be found in the corresponding source file */

        Base(int _id, Ownership _ownership, Type_of_unit _unit_under_construction);
        Base(int _id, Ownership _ownership);
        ~Base();
};