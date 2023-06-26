#include "Swordsman.hpp"

/**
 * @brief Construct a new Swordsman:: Swordsman object
 * 
 * @param _stamina 
 * @param _id 
 * @param _ownership 
 */
Swordsman::Swordsman(int _stamina, int _id, Ownership _ownership):
                     Unit(_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};

/**
 * @brief Construct a new Swordsman:: Swordsman object
 * 
 * @param _id 
 * @param _ownership 
 */
Swordsman::Swordsman(int _id, Ownership _ownership):
                     Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};

/**
 * @brief Destroy the Swordsman:: Swordsman object
 * 
 */
Swordsman::~Swordsman(){};

