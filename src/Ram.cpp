#include "Ram.hpp"

Ram::Ram(int _stamina):
         Unit(_stamina, _speed, _cost, _attack_range, _building_time){};\

Ram::Ram():
         Unit(_default_stamina, _speed, _cost, _attack_range, _building_time){};

Ram::~Ram(){};

