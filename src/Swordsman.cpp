#include "Swordsman.hpp"

Swordsman::Swordsman(int _stamina):
                     Unit(_stamina, _speed, _cost, _attack_range, _building_time){};


Swordsman::Swordsman():
                     Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

Swordsman::~Swordsman(){};

