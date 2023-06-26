#include "Unit.hpp"

/**
 * @brief Construct a new Unit:: Unit object
 * 
 * @param _stamina 
 * @param _speed 
 * @param _cost 
 * @param _attack_range 
 * @param _building_time 
 * @param _id 
 * @param _type_of_unit 
 * @param _ownership 
 */

Unit::Unit(int _stamina, 
           int _speed, 
           int _cost, 
           int _attack_range, 
           int _building_time,
           int _id,
           Type_of_unit _type_of_unit,
           Ownership _ownership):

            stamina(_stamina),
            speed(_speed),
            cost(_cost),
            attack_range(_attack_range),
            building_time(_building_time),
            id(_id),
            type_of_unit(_type_of_unit),
            ownership(_ownership){}

/**
 * @brief Get the unit's stamina.
 * @return int Stamina value.
 */
  int Unit::get_stamina() const{
    return stamina;
}

/**
 * @brief Set the unit's stamina.
 * @param value New stamina value.
 */
  void Unit::set_stamina(int value){
    stamina = value;
}

/**
 * @brief Get the unit's speed.
 * @return int Speed value.
 */
  int Unit::get_speed() const{
    return speed;
}

/**
 * @brief Set the unit's speed.
 * @param value New speed value.
 */
  void Unit::set_speed(int value){
    speed = value;
}

/**
 * @brief Get the unit's cost.
 * @return int Cost value.
 */
  int Unit::get_cost() const{
    return cost;
}

/**
 * @brief Set the unit's cost.
 * @param value New cost value.
 */
  void Unit::set_cost(int value){
    cost = value;
}

/**
 * @brief Get the unit's attack range.
 * @return int Attack range value.
 */
   int Unit::get_attack_range() const{
    return attack_range;
}

/**
 * @brief Set the unit's attack range.
 * @param value New attack range value.
 */
  void Unit::set_attack_range(int value){
    attack_range = value;
}

/**
 * @brief Get the unit's building time.
 * @return int Building time value.
 */
  int Unit::get_building_time() const{
    return building_time;
}

/**
 * @brief Set the unit's building time.
 * @param value New building time value.
 */
  void Unit::set_building_time(int value){
    building_time = value;
}
/**
 * @brief Returns the unit's id
 * 
 * @return int id
 */
int Unit::get_id() const{
  return id;
}

/**
 * @brief Returns the unit's type.
 * @return Type of the unit.
 */
Type_of_unit Unit::get_type_of_unit() const{
  return type_of_unit;
}

/**
 * @brief Returns the unit's ownership.
 * @return Ownership of the unit.
 */
Ownership Unit::get_ownership() const{
  return ownership;
}



/**
 * @brief Destroy the Unit:: Unit object
 * 
 */
Unit::~Unit(){}