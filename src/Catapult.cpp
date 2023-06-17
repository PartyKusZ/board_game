#include "Catapult.hpp"
/**
 * @brief Construct a new Catapult:: Catapult object
 * 
 * @param _stamina 
 */
Catapult::Catapult(int _stamina):
                   Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Construct a new Catapult:: Catapult object
 * 
 */

Catapult::Catapult():
                   Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Destroy the Catapult:: Catapult object
 * 
 */
Catapult::~Catapult(){};