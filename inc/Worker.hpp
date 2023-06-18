#pragma once 
#include "Unit.hpp"

/**
 * @brief  Class representing an Worker unit
 * 
 */


class Worker: public Unit{
    private:
        static constexpr int _default_stamina = 20; //!< default stamina
        static constexpr int _speed = 2;            //!< default speed
        static constexpr int _cost = 100;           //!< default cost
        static constexpr int _attack_range = 1;     //!< default attack range
        static constexpr int _building_time = 2;    //!< default building time
        static constexpr Type_of_unit _unit = Type_of_unit::WORKER; //!< unit type
    public:
    /*Method descriptions can be found in the corresponding source file */

        Worker(int _stamina, Ownership _ownership);
        Worker(Ownership _ownership);
        ~Worker();
};