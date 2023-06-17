#include "Catapult.hpp"
/**
 * @brief Construct a new Catapult:: Catapult object
 * 
 * @param _stamina 
 */
Catapult::Catapult(int _stamina, Ownership _ownership):
                   Unit(_stamina, _speed, _cost, _attack_range, _building_time, Type_of_unit::CATAPULT,_ownership){};

/**
 * @brief Construct a new Catapult:: Catapult object
 * 
 */

Catapult::Catapult(Ownership _ownership):
                   Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, Type_of_unit::CATAPULT, _ownership){};

/**
 * @brief Destroy the Catapult:: Catapult object
 * 
 */
Catapult::~Catapult(){};