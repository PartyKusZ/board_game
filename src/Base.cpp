#include "Base.hpp"
/**
 * @brief Construct a new Base:: Base object
 * 
 */
Base::Base(Ownership _ownership):
           Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};

/**
 * @brief Destroy the Base:: Base object
 * 
 */
Base::~Base(){};