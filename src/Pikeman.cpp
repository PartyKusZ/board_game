#include "Pikeman.hpp"
/**
 * @brief Construct a new Pikeman:: Pikeman object
 * 
 * @param _stamina 
 */
Pikeman::Pikeman(int _stamina, Ownership _ownership): 
                 Unit(_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};


/**
 * @brief Construct a new Pikeman:: Pikeman object
 * 
 */
Pikeman::Pikeman(Ownership _ownership): 
                 Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};

/**
 * @brief Destroy the Pikeman:: Pikeman object
 * 
 */
Pikeman::~Pikeman(){};