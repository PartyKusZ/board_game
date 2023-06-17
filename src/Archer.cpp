#include "Archer.hpp"
/**
 * @brief Construct a new Archer:: Archer object
 * 
 * @param _stamina 
 */
Archer::Archer(int _stamina, Ownership _ownership):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};
/**
 * @brief Construct a new Archer:: Archer object
 * 
 */
Archer::Archer(Ownership _ownership):
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time,  _unit, _ownership){};


/**
 * @brief Destroy the Archer:: Archer object
 * 
 */
Archer::~Archer(){};