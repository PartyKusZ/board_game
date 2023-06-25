#include "Commander.hpp"
/**
 * @brief Construct a new Commander:: Commander object
 * 
 * @param _state  represents the current state of the game; position of units on the map and amount of gold 
 */
Commander::Commander(Game_state _state): floodfill(_state.map){

    my_base = dynamic_cast<Base *>(game_state.find_base(Ownership::MINE));
    enemy_base = dynamic_cast<Base *>(game_state.find_base(Ownership::ENEMIES));

    my_units = game_state.find_all_units(Ownership::MINE);
    enemy_units = game_state.find_all_units(Ownership::ENEMIES);

    mines = game_state.find_mines();

    attack_table[Type_of_unit::KNIGHT][Type_of_unit::KNIGHT] = 35;

   attack_table[Type_of_unit::KNIGHT] = {
        {Type_of_unit::KNIGHT, 35},
        {Type_of_unit::SWORDSMAN, 35},
        {Type_of_unit::ARCHER, 35},
        {Type_of_unit::PIKEMAN, 35},
        {Type_of_unit::CATAPULT, 35},
        {Type_of_unit::RAM, 50},
        {Type_of_unit::WORKER, 35},
        {Type_of_unit::BASE, 35}
    };

   attack_table[Type_of_unit::SWORDSMAN] = {
        {Type_of_unit::KNIGHT, 30},
        {Type_of_unit::SWORDSMAN, 30},
        {Type_of_unit::ARCHER, 30},
        {Type_of_unit::PIKEMAN, 20},
        {Type_of_unit::CATAPULT, 20},
        {Type_of_unit::RAM, 30},
        {Type_of_unit::WORKER, 30},
        {Type_of_unit::BASE, 30}
    };

   attack_table[Type_of_unit::ARCHER] = {
        {Type_of_unit::KNIGHT, 15},
        {Type_of_unit::SWORDSMAN, 15},
        {Type_of_unit::ARCHER, 15},
        {Type_of_unit::PIKEMAN, 15},
        {Type_of_unit::CATAPULT, 10},
        {Type_of_unit::RAM, 10},
        {Type_of_unit::WORKER, 15},
        {Type_of_unit::BASE, 15}
    };

   attack_table[Type_of_unit::PIKEMAN] = {
        {Type_of_unit::KNIGHT, 35},
        {Type_of_unit::SWORDSMAN, 15},
        {Type_of_unit::ARCHER, 15},
        {Type_of_unit::PIKEMAN, 15},
        {Type_of_unit::CATAPULT, 15},
        {Type_of_unit::RAM, 10},
        {Type_of_unit::WORKER, 15},
        {Type_of_unit::BASE, 10}
    };

   attack_table[Type_of_unit::CATAPULT] = {
        {Type_of_unit::KNIGHT, 40},
        {Type_of_unit::SWORDSMAN, 40},
        {Type_of_unit::ARCHER, 40},
        {Type_of_unit::PIKEMAN, 40},
        {Type_of_unit::CATAPULT, 40},
        {Type_of_unit::RAM, 40},
        {Type_of_unit::WORKER, 40},
        {Type_of_unit::BASE, 50}
    };

   attack_table[Type_of_unit::RAM] = {
        {Type_of_unit::KNIGHT, 10},
        {Type_of_unit::SWORDSMAN, 10},
        {Type_of_unit::ARCHER, 10},
        {Type_of_unit::PIKEMAN, 10},
        {Type_of_unit::CATAPULT, 10},
        {Type_of_unit::RAM, 10},
        {Type_of_unit::WORKER, 10},
        {Type_of_unit::BASE, 50}
    };

   attack_table[Type_of_unit::WORKER] = {
        {Type_of_unit::KNIGHT, 5},
        {Type_of_unit::SWORDSMAN, 5},
        {Type_of_unit::ARCHER, 5},
        {Type_of_unit::PIKEMAN, 5},
        {Type_of_unit::CATAPULT, 5},
        {Type_of_unit::RAM, 5},
        {Type_of_unit::WORKER, 5},
        {Type_of_unit::BASE, 1}
    };


}


/**
 * @brief Returns the difference in stamina between the player's base and the opponent's base. 
 * If positive the result is in favour of the player and if negative it is in favour of the opponent
 * 
 * @return int  base health coefficient 
 */
int Commander::base_with_more_stamina(){
    return my_base->get_stamina() - enemy_base->get_stamina();
}

int Commander::average_unit_stamina(std::vector<Unit *> units){
    int sum = 0;
    for(auto unit: units){
        sum += unit->get_stamina();
    }
    return sum / my_units.size();
}

int Commander::average_unit_speed(std::vector<Unit *> units){
    int sum = 0;
    for(auto unit: units){
        sum += unit->get_speed();
    }
    return sum / my_units.size();
}

int Commander::average_unit_attack_range(std::vector<Unit *> units){
    int sum = 0;
    for(auto unit: units){
        sum += unit->get_attack_range();
    }
    return sum / my_units.size();
}

int Commander::num_of_units_around_base(Base *base, std::vector<Unit *> units, int range){
    int sum = 0;
    for(auto unit: units){
        if(game_state.distance_between_units(base,unit) <= range){
            ++sum;
        }
    }
    return sum;
}

int Commander::damage_inflicited(Type_of_unit attacker, Type_of_unit attacked){
    return attack_table[attacker][attacked];
}

Ownership Commander::who_will_win_skirmish(Unit *my_unit, Unit *enemy_unit){
    int my_stamina = my_unit->get_stamina();
    int enemy_stamina = enemy_unit->get_stamina();
    int my_attack = damage_inflicited(my_unit->get_type_of_unit(),enemy_unit->get_type_of_unit());
    int enemy_attack = damage_inflicited(enemy_unit->get_type_of_unit(),my_unit->get_type_of_unit());
    while(my_stamina > 0 || enemy_stamina > 0){
        my_stamina -= enemy_attack;
        enemy_stamina -= my_attack;
    }
    if(my_stamina > enemy_stamina){
        return Ownership::MINE;
    }else{
        return Ownership::ENEMIES;
    }
}

/**
 * @brief Destroy the Commander:: Commander object
 * 
 */

Commander::~Commander(){}
