#include "Archer.hpp"
/**
 * @brief Construct a new Archer:: Archer object
 * 
 * @param _stamina 
 */
Archer::Archer(int _stamina):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time){};
/**
 * @brief Construct a new Archer:: Archer object
 * 
 */
Archer::Archer():
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};


/**
 * @brief Destroy the Archer:: Archer object
 * 
 */
Archer::~Archer(){};