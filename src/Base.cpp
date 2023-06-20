#include "Base.hpp"
/**
 * @brief Construct a new Base:: Base object
 * 
 */
Base::Base(int _id, Ownership _ownership):
           Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};

/**
 * @brief Destroy the Base:: Base object
 * 
 */
Base::~Base(){};