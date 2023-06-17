#include "Pikeman.hpp"

Pikeman::Pikeman(int _stamina): 
                 Unit(_stamina, _speed, _cost, _attack_range, _building_time){};


Pikeman::Pikeman(): 
                 Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

Pikeman::~Pikeman(){};