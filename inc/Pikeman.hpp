#pragma once 
#include "Unit.hpp"

/**
 * @brief  Class representing an Pikeman unit
 * 
 */

class Pikeman: public Unit{
    public:
        static constexpr int _default_stamina = 50; //!< default stamina
        static constexpr int _speed = 2;            //!< default speed
        static constexpr int _cost = 200;           //!< default cost
        static constexpr int _attack_range = 2;     //!< default attack range
        static constexpr int _building_time = 3;    //!< default building time
        
        static constexpr Type_of_unit _unit = Type_of_unit::PIKEMAN; //!< unit type

    
    /*Method descriptions can be found in the corresponding source file */

        Pikeman(int _stamina, int _id,  Ownership _ownership);
        Pikeman(int _id, Ownership _ownership);
        ~Pikeman();
};