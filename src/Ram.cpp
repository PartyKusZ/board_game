#include "Ram.hpp"

/**
 * @brief Construct a new Ram:: Ram object
 * 
 * @param _stamina 
 */
Ram::Ram(int _stamina, int _id, Ownership _ownership):
         Unit(_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};

/**
 * @brief Construct a new Ram:: Ram object
 * 
 */
Ram::Ram(int _id, Ownership _ownership):
         Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};

/**
 * @brief Destroy the Ram:: Ram object
 * 
 */
Ram::~Ram(){};

