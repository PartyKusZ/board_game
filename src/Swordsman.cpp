#include "Swordsman.hpp"

/**
 * @brief Construct a new Swordsman:: Swordsman object
 * 
 * @param _stamina 
 */
Swordsman::Swordsman(int _stamina):
                     Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Construct a new Swordsman:: Swordsman object
 * 
 */
Swordsman::Swordsman():
                     Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Destroy the Swordsman:: Swordsman object
 * 
 */
Swordsman::~Swordsman(){};

