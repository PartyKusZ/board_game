#include "Unit.hpp"

Unit::Unit(int _stamina, 
           int _speed, 
           int _cost, 
           int _attack_range, 
           int _building_time):

            stamina(_stamina),
            speed(_speed),
            cost(_cost),
            attack_range(_attack_range),
            building_time(_building_time){}

inline int Unit::get_stamina() const{
    return stamina;
}

inline void Unit::set_stamina(int value){
    stamina = value;
}

inline int Unit::get_speed() const{
    return speed;
}

inline void Unit::set_speed(int value){
    speed = value;
}

inline int Unit::get_cost() const{
    return cost;
}

inline void Unit::set_cost(int value){
    cost = value;
}

inline int Unit::get_attack_range() const{
    return attack_range;
}

inline void Unit::set_attack_range(int value){
    attack_range = value;
}

inline int Unit::get_building_time() const{
    return building_time;
}

inline void Unit::set_building_time(int value){
    building_time = value;
}


Unit::~Unit(){}