#include "Ram.hpp"

/**
 * @brief Construct a new Ram:: Ram object
 * 
 * @param _stamina 
 */
Ram::Ram(int _stamina):
         Unit(_stamina, _speed, _cost, _attack_range, _building_time){};\

/**
 * @brief Construct a new Ram:: Ram object
 * 
 */
Ram::Ram():
         Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Destroy the Ram:: Ram object
 * 
 */
Ram::~Ram(){};

