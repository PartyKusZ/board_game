#include "Pikeman.hpp"
/**
 * @brief Construct a new Pikeman:: Pikeman object
 * 
 * @param _stamina 
 */
Pikeman::Pikeman(int _stamina): 
                 Unit(_stamina, _speed, _cost, _attack_range, _building_time){};


/**
 * @brief Construct a new Pikeman:: Pikeman object
 * 
 */
Pikeman::Pikeman(): 
                 Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Destroy the Pikeman:: Pikeman object
 * 
 */
Pikeman::~Pikeman(){};