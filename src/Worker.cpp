#include "Worker.hpp"

Worker::Worker(int _stamina, 
               int _speed, 
               int _cost, 
               int _attack_range, 
               int _building_time):
               
               Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

Worker::~Worker(){};            