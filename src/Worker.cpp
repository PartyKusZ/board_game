#include "Worker.hpp"

/**
 * @brief Construct a new Worker:: Worker object
 * 
 * @param _stamina 
 */
Worker::Worker(int _stamina):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Construct a new Worker:: Worker object
 * 
 */
Worker::Worker():
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

/**
 * @brief Destroy the Worker:: Worker object
 * 
 */
Worker::~Worker(){};            