#include "Swordsman.hpp"

/**
 * @brief Construct a new Swordsman:: Swordsman object
 * 
 * @param _stamina 
 */
Swordsman::Swordsman(int _stamina, Ownership _ownership):
                     Unit(_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};

/**
 * @brief Construct a new Swordsman:: Swordsman object
 * 
 */
Swordsman::Swordsman(Ownership _ownership):
                     Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};

/**
 * @brief Destroy the Swordsman:: Swordsman object
 * 
 */
Swordsman::~Swordsman(){};

