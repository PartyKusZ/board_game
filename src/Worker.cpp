#include "Worker.hpp"

/**
 * @brief Construct a new Worker:: Worker object
 * 
 * @param _stamina 
 */
Worker::Worker(int _stamina, Ownership _ownership):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};

/**
 * @brief Construct a new Worker:: Worker object
 * 
 */
Worker::Worker(Ownership _ownership):
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time, _unit, _ownership){};

/**
 * @brief Destroy the Worker:: Worker object
 * 
 */
Worker::~Worker(){};            