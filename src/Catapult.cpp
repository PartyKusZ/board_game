#include "Catapult.hpp"

Catapult::Catapult(int _stamina):
                   Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

Catapult::Catapult():
                   Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};


Catapult::~Catapult(){};