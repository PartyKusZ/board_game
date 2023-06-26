#include "Base.hpp"
/**
 * @brief Construct a new Base:: Base object
 * 
 * @param _stamina 
 * @param _id 
 * @param _ownership 
 */
Base::Base(int _stamina, int _id, Ownership _ownership):
           Unit(_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};

/**
 * @brief Construct a new Base:: Base object
 * 
 * @param _stamina 
 * @param _id 
 * @param _ownership 
 * @param _unit_under_construction 
 */
Base::Base(int _stamina, int _id, Ownership _ownership, Type_of_unit _unit_under_construction):
           unit_under_construction(_unit_under_construction), 
           under_construction(true),
           Unit(_stamina, _speed, _cost, _attack_range, _building_time, _id, _unit, _ownership){};



/**
 * @brief Destroy the Base:: Base object
 * 
 */
Base::~Base(){};