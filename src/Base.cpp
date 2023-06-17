#include "Base.hpp"
/**
 * @brief Construct a new Base:: Base object
 * 
 */
Base::Base():
           Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Destroy the Base:: Base object
 * 
 */
Base::~Base(){};