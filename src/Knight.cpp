#include "Knight.hpp"
/**
 * @brief Construct a new Knight:: Knight object
 * 
 * @param _stamina 
 */
Knight::Knight(int _stamina):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Construct a new Knight:: Knight object
 * 
 */
Knight::Knight():
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Destroy the Knight:: Knight object
 * 
 */
Knight::~Knight(){};
