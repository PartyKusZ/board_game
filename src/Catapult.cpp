#include "Catapult.hpp"
/**
 * @brief Construct a new Catapult:: Catapult object
 * 
 * @param _stamina 
 * @param _id 
 * @param _ownership 
 */
Catapult::Catapult(int _stamina, int _id, Ownership _ownership):
                   Unit(_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit,_ownership){};

/**
 * @brief Construct a new Catapult:: Catapult object
 * 
 * @param _id 
 * @param _ownership 
 */

Catapult::Catapult(int _id, Ownership _ownership):
                   Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _id,  _unit, _ownership){};

/**
 * @brief Destroy the Catapult:: Catapult object
 * 
 */
Catapult::~Catapult(){};