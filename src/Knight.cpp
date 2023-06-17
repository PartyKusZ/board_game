#include "Knight.hpp"

Knight::Knight(int _stamina):
               Unit(_stamina, _speed, _cost, _attack_range, _building_time){};

Knight::Knight():
               Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

Knight::~Knight(){};
