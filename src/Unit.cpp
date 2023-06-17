#include "Unit.hpp"

/**
* @brief Construct a new Unit object
* 
* @param _stamina Stamina of unit
* @param _speed Speed of of unit
* @param _cost Cost of unit
* @param _attack_range Attack range of unit
* @param _building_time Building time of unit
*/

Unit::Unit(int _stamina, 
           int _speed, 
           int _cost, 
           int _attack_range, 
           int _building_time):

            stamina(_stamina),
            speed(_speed),
            cost(_cost),
            attack_range(_attack_range),
            building_time(_building_time){}

/**
 * @brief Get the unit's stamina.
 * @return int Stamina value.
 */
inline int Unit::get_stamina() const{
    return stamina;
}

/**
 * @brief Set the unit's stamina.
 * @param value New stamina value.
 */
inline void Unit::set_stamina(int value){
    stamina = value;
}

/**
 * @brief Get the unit's speed.
 * @return int Speed value.
 */
inline int Unit::get_speed() const{
    return speed;
}

/**
 * @brief Set the unit's speed.
 * @param value New speed value.
 */
inline void Unit::set_speed(int value){
    speed = value;
}

/**
 * @brief Get the unit's cost.
 * @return int Cost value.
 */
inline int Unit::get_cost() const{
    return cost;
}

/**
 * @brief Set the unit's cost.
 * @param value New cost value.
 */
inline void Unit::set_cost(int value){
    cost = value;
}

/**
 * @brief Get the unit's attack range.
 * @return int Attack range value.
 */
inline int Unit::get_attack_range() const{
    return attack_range;
}

/**
 * @brief Set the unit's attack range.
 * @param value New attack range value.
 */
inline void Unit::set_attack_range(int value){
    attack_range = value;
}

/**
 * @brief Get the unit's building time.
 * @return int Building time value.
 */
inline int Unit::get_building_time() const{
    return building_time;
}

/**
 * @brief Set the unit's building time.
 * @param value New building time value.
 */
inline void Unit::set_building_time(int value){
    building_time = value;
}


/**
 * @brief Destroy the Unit:: Unit object
 * 
 */
Unit::~Unit(){}