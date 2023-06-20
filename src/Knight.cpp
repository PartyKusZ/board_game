#include "Knight.hpp"
/**
 * @brief Construct a new Knight:: Knight object
 * 
 * @param _stamina 
 */
Knight::Knight(int _stamina, int _id, Ownership _ownership):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};

/**
 * @brief Construct a new Knight:: Knight object
 * 
 */
Knight::Knight(int _id, Ownership _ownership):
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _id,  _unit, _ownership){};

/**
 * @brief Destroy the Knight:: Knight object
 * 
 */
Knight::~Knight(){};
