#include "Commander.hpp"
/**
 * @brief Construct a new Commander:: Commander object
 * 
 * @param _state  represents the current state of the game; position of units on the map and amount of gold 
 */
Commander::Commander(Game_state _state): game_state(_state){

    my_base = dynamic_cast<Base *>(game_state.find_base(Ownership::MINE));
    enemy_base = dynamic_cast<Base *>(game_state.find_base(Ownership::ENEMIES));

    my_units = game_state.find_all_units(Ownership::MINE);
    enemy_units = game_state.find_all_units(Ownership::ENEMIES);

    mines = game_state.find_mines();


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

/**
 * @brief Calculates the average stamina of the units provided.
 * 
 * @param units Vector of units to average the stamina of.
 * @return The average stamina of the units. 
 */

int Commander::average_unit_stamina(std::vector<Unit *> units){
    int sum = 0;
    for(auto unit: units){
        sum += unit->get_stamina();
    }
    if( my_units.size() == 0){
        return sum;
    }
    return sum / my_units.size();
}

/**
 * @brief Calculates the average speed of the units provided.
 * 
 * @param units Vector of units to average the speed of.
 * @return The average speed of the units.
 */

int Commander::average_unit_speed(std::vector<Unit *> units){
    int sum = 0;
    for(auto unit: units){
        sum += unit->get_speed();
    }
    if( my_units.size() == 0){
        return sum;
    }

    return sum / my_units.size();
}


/**
 * @brief Calculates the average attack range of the units provided.
 * 
 * @param units Vector of units to average the attack range of.
 * @return The average attack range of the units.
 */

int Commander::average_unit_attack_range(std::vector<Unit *> units){
    int sum = 0;
    for(auto unit: units){
        sum += unit->get_attack_range();
    }
    if( my_units.size() == 0){
        return sum;
    }
    return sum / my_units.size();
}

/**
 * @brief Calculates the percentage of units within a given range of a base.
 * 
 * @param base The base to measure distance from.
 * @param units Vector of units to check the distance of.
 * @param range The range within which units are considered to be 'around' the base.
 * @return The percentage of units within the given range of the base.
 */

int Commander::percent_of_units_around_base(Base *base, std::vector<Unit *> units, int range){
    int sum = 0;
    for(auto unit: units){
        if(game_state.distance_between_units(base,unit) <= range){
            ++sum;
        }
    }
    if( my_units.size() == 0){
        return sum;
    }
    return sum / units.size();
}
/**
 * @brief Calculates the percentage of units within a given range of a mine.
 * 
 * @param mine The mine's coordinates to measure distance from.
 * @param units Vector of units to check the distance of.
 * @param range The range within which units are considered to be 'around' the mine.
 * @return The percentage of units within the given range of the mine.
 */
int Commander::percent_of_units_around_mine(Coordinartes mine, std::vector<Unit *> units, int range){
    int sum = 0;
    for(auto unit: units){
        if(game_state.distance_between_units(mine,unit) <= range){
            ++sum;
        }
    }
    if( my_units.size() == 0){
        return sum;
    }
    return sum / units.size();
}




/**
 * @brief Retrieves the damage value from a given attacker to a given attacked unit type from a predefined table.
 * 
 * @param attacker The type of the unit attacking.
 * @param attacked The type of the unit being attacked.
 * @return The damage inflicted from the attacker to the attacked.
 */

int Commander::damage_inflicited(Type_of_unit attacker, Type_of_unit attacked){
    return attack_table[attacker][attacked];
}

/**
 * @brief Identifies the enemy units within the attack range of a given unit.
 * 
 * @param my_unit The unit from which to measure the attack range.
 * @param enemies_unit Vector of enemy units to check for being within the attack range.
 * @return A vector of enemy units that are within the attack range of the given unit.
 */

std::vector<Unit *> Commander::are_units_in_attack_range(Unit *my_unit, std::vector<Unit *> enemies_unit){
    std::vector<Unit *> units_in_attack_range;
    for(auto unit: enemies_unit){
        if(game_state.distance_between_units(my_unit,unit) <= my_unit->get_attack_range()){
            units_in_attack_range.push_back(unit);
        }
    }
    return units_in_attack_range;
}


/**
 * @brief Simulates a skirmish between a unit owned by the commander and an enemy unit, and predicts the winner.
 * 
 * @param my_unit The unit owned by the commander.
 * @param enemy_unit The enemy unit.
 * @return The predicted ownership of the winning unit after the skirmish.
 */

Ownership Commander::who_will_win_skirmish(Unit *my_unit, Unit *enemy_unit){
    int my_stamina = my_unit->get_stamina();
    int enemy_stamina = enemy_unit->get_stamina();
    int my_attack = damage_inflicited(my_unit->get_type_of_unit(),enemy_unit->get_type_of_unit());
    int enemy_attack = damage_inflicited(enemy_unit->get_type_of_unit(),my_unit->get_type_of_unit());
    while(my_stamina > 0 && enemy_stamina > 0){
        enemy_stamina -= my_attack;
        my_stamina -= enemy_attack;
    }
    if(my_stamina > enemy_stamina){
        return Ownership::MINE;
    }else{
        return Ownership::ENEMIES;
    }
}


void Commander::move_unit(Unit *unit, Coordinartes xy, int speed){
    Floodfill floodfill(game_state.map);
    Coordinartes target;
    std::string order;
    floodfill.floodfill(game_state.get_coordinate_by_id(unit),xy);
    auto path = floodfill.get_path(game_state.get_coordinate_by_id(unit),xy);
    if(floodfill.is_filed_free(xy)){
        path.push_back(xy);    
    }
    if(path.size() > 0){
        if(path.size() > speed){
            target = path[speed]; 
        }else{
            target = path[path.size()-1];
        }
        order += std::to_string(unit->get_id()) + " ";
        order += "M ";
        order += std::to_string(target.x) + " ";
        order += std::to_string(target.y);
        order += "\n";
        std::lock_guard<std::mutex> guard(mutex);
        orders.push_back(order);
    }
}

void Commander::attack_unit(Unit *unit_1, Unit *unit_2){

    std::string order;
    order += std::to_string(unit_1->get_id()) + " ";
    order += "A ";
    order += std::to_string(unit_2->get_id());
    order += "\n";
    orders.push_back(order);
    unit_2->set_stamina(unit_2->get_stamina() - damage_inflicited(unit_1->get_type_of_unit(),unit_2->get_type_of_unit()));
    if(unit_2->get_stamina() < 1){
        game_state.remove_unit_by_id(unit_2->get_id());
        enemy_units = game_state.find_all_units(Ownership::ENEMIES);
    }

}



void Commander::create_unit(Type_of_unit unit){
    
    std::string order;
    order += std::to_string(my_base->get_id()) + " ";
    order += "B ";
    if(unit == Type_of_unit::KNIGHT){
        order += "K";
    }else if(unit == Type_of_unit::SWORDSMAN){
        order += "S";
    }else if(unit == Type_of_unit::ARCHER){
        order += "A";
    }else if(unit == Type_of_unit::PIKEMAN){
        order += "P";
    }else if(unit == Type_of_unit::CATAPULT){
        order += "C";
    }else if(unit == Type_of_unit::RAM){
        order += "R";
    }else if(unit == Type_of_unit::WORKER){
        order += "W";
    }
    order += "\n";
    orders.push_back(order);
    
    
}


int Commander::number_of_units_relatively(std::vector<Unit *> units){
    
    if(my_units.size() == 0 && enemy_units.size() == 0){
        return 0;
    }else{
        return units.size() / (my_units.size() + enemy_units.size());
    }
}

void Commander::give_orders(const char *filename){
    // move_unit(my_units[0],game_state.get_coordinate_by_id(enemy_base));
    // for(int i = 0; i <  my_units.size(); ++i){
    //     for(int j = 0; j < enemy_units.size(); ++j){
    //         if(game_state.is_enemy_within_attack_range(my_units[i],enemy_units[j])){
    //             attack_unit(my_units[i],enemy_units[j]);
    //         }
    //     }
    // }
    // if(!my_base->is_under_construction()){
    //     create_unit(Type_of_unit::ARCHER);
    // }
    // for(auto order: orders){
    //     std::cout<<order;
    // }
   
    // int bases_stamina_ratio = base_with_more_stamina();
    // int my_average_stamina = average_unit_stamina(my_units);
    // int enemies_average_stamina = average_unit_stamina(enemy_units);
    // int my_average_speed = average_unit_speed(my_units);
    // int enemies_average_speed = average_unit_speed(enemy_units);
    // int my_average_attack_range = average_unit_attack_range(my_units);
    // int enemies_average_attack_range = average_unit_attack_range(enemy_units);

    /**UNITS CREATING*/

    if(my_units.size() == 0 && enemy_units.size() == 0){ // no units on map 
        if(!my_base->is_under_construction()){
            create_unit(Type_of_unit::KNIGHT);
            game_state.gold_amount -= Knight::_cost;
        }
    }else if(game_state.gold_amount < 500){ // if i have no to much gold
        if(!my_base->is_under_construction()){
            create_unit(Type_of_unit::WORKER);
            game_state.gold_amount -= Worker::_cost;
        }


    }else if(average_unit_stamina(my_units) < average_unit_stamina(enemy_units)){ // if enemy has more average stamina
        if(game_state.gold_amount < 200){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::WORKER);
                game_state.gold_amount -= Worker::_cost;
            }
        }else if(game_state.gold_amount < 250){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::PIKEMAN);
                game_state.gold_amount -= Pikeman::_cost;
            }
        }else if(game_state.gold_amount < 300){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::SWORDSMAN);
                game_state.gold_amount -= Swordsman::_cost;
            }
        }else if(game_state.gold_amount < 400){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::ARCHER);
                game_state.gold_amount -= Archer::_cost;
            }
        }else if(game_state.gold_amount < 500){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::KNIGHT);
                game_state.gold_amount -= Knight::_cost;
            }
        }else if(game_state.gold_amount < 800){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::RAM);
                game_state.gold_amount -= Ram::_cost;
            }
        }else if(game_state.gold_amount >= 800){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::CATAPULT);
                game_state.gold_amount -= Archer::_cost;
            }
        }
    }else{
        if(game_state.gold_amount >= 800){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::CATAPULT);
                game_state.gold_amount -= Catapult::_cost;
            }
        }else if(game_state.gold_amount < 800){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::ARCHER);
                game_state.gold_amount -= Archer::_cost;
            }
        }
    }


    /*UNITS MOVMENT AND ATTACK*/

        /*ATTACK*/
    for(int i = 0; i < my_units.size(); ++i){
            for(int j = 0; j < enemy_units.size(); ++j){
                if(game_state.is_enemy_within_attack_range(my_units[i],enemy_units[j])){
                    if(who_will_win_skirmish(my_units[i],enemy_units[j]) == Ownership::MINE){ // simulating who is likely to win
                        attack_unit(my_units[i],enemy_units[j]);
                        my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                    }
                }
            }
            
    }
        /*MOVE*/
           
    if(base_with_more_stamina() - percent_of_units_around_base(my_base,enemy_units, 0.5*(game_state.map.size() + game_state.map[0].size()) / 2) > 0){ // good for me    
        for(int i = 0; i < my_units.size(); ++i){
            if(my_units[i]->get_type_of_unit() != Type_of_unit::WORKER){
                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));            
            }else{
                auto mines = game_state.find_mines();
                if(mines.size() > 0){
                    std::vector<int> dist;
                    for(auto mine: mines){
                        dist.push_back(game_state.distance_between_units(mine,my_units[i]));
                    }
                    auto min_elem = std::min_element(dist.begin(),dist.end());
                    auto index = std::distance(dist.begin(), min_elem);
                    threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], mines[index], my_units[i]->get_speed()));            

                }
                
            }
        }
        for(int i = 0; i < threads.size(); ++i){
            threads[i].join();
        }
    }else{
        for(int i = 0; i < my_units.size(); ++i){
            threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(my_base), my_units[i]->get_speed()));            
        }
        for(int i = 0; i < threads.size(); ++i){
            threads[i].join();
        }
    }


    File_parser::save_orders(filename,orders);



for(auto order: orders){
        std::cout<<order;
    }





}



/**
 * @brief Destroy the Commander:: Commander object
 * 
 */

Commander::~Commander(){}
