#include "Archer.hpp"

Archer::Archer(int _stamina):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

Archer::Archer():
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};



Archer::~Archer(){};