#include "Worker.hpp"

Worker::Worker(int _stamina):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

Worker::Worker():
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

Worker::~Worker(){};            