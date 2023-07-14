#include "Commander.hpp"
/**
 * @brief Constructor for the Commander class.
 *
 * This constructor is responsible for initializing the game state,
 * populating lists of the player's and enemy's units, assigning the player's 
 * and enemy's bases, and setting up an attack table for each unit type, indicating 
 * their attack power against different unit types.
 *
 * @param _state The current state of the game.
 */
Commander::Commander(Game_state _state): game_state(_state), enemie_forces_analysis(File_parser::get_enemie_forces()){

    try{
        my_base = dynamic_cast<Base *>(game_state.find_base(Ownership::MINE));
        if(my_base == nullptr){
            throw std::invalid_argument("my_base is nullptr");
        }
        enemy_base = dynamic_cast<Base *>(game_state.find_base(Ownership::ENEMIES));
        if(enemy_base == nullptr){
            throw std::invalid_argument("enemy_base is nullptr");
        }
    }
    catch (const std::invalid_argument& ia){
        std::cerr << "Commander::Commander(): Invalid argument: " << ia.what() << '\n';
        exit(EXIT_FAILURE); // Zwracamy kod błędu
    }

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

std::vector<Type_of_unit> Commander::what_can_i_build(){
    std::vector<Type_of_unit> units;
    if(game_state.gold_amount >= 100){
        units.push_back(Type_of_unit::WORKER);
    }
    if(game_state.gold_amount >= 200){
        units.push_back(Type_of_unit::PIKEMAN);
    }
    if(game_state.gold_amount >= 250){
        units.push_back(Type_of_unit::ARCHER);
        units.push_back(Type_of_unit::SWORDSMAN);
    }
    if(game_state.gold_amount >= 400){
        units.push_back(Type_of_unit::KNIGHT);
    }
    if(game_state.gold_amount >= 500){
        units.push_back(Type_of_unit::RAM);
    }
    if(game_state.gold_amount >= 800){
        units.push_back(Type_of_unit::CATAPULT);
    }   
    return units;
}

/**
 * @brief Moves a given unit to a specified coordinate on the map at a given speed.
 * 
 * This function uses the Floodfill algorithm to find the shortest path from 
 * the unit's current position to the target position. If the target position
 * is free, it is added to the path. Then, it determines the next target position 
 * on this path, limited by the unit's speed. A string order to move the unit 
 * to the target position is constructed and added to the list of orders in a 
 * thread-safe manner.
 *
 * @param unit A pointer to the unit that will be moved.
 * @param xy The target coordinate on the map.
 * @param speed The speed of the unit.
 */
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
            for(int i = 0; i < path.size(); ++i){
                if(game_state.distance_between_units(path[i],game_state.get_coordinate_by_id(unit)) == speed){
                    target = path[i];
                    break;
                }
            }
            target = path[speed]; // stare rozwiązanie
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

/**
 * @brief Makes one unit attack another.
 * 
 * This function creates a string order for one unit to attack another. The order 
 * string is then added to the list of orders. The attacked unit's stamina is 
 * reduced according to the damage inflicted by the attacking unit. If the attacked 
 * unit's stamina falls below 1, it is removed from the game state and the list 
 * of enemy units is updated.
 *
 * @param unit_1 A pointer to the attacking unit.
 * @param unit_2 A pointer to the unit being attacked.
 */

void Commander::attack_unit(Unit *unit_1, Unit *unit_2){

    std::string order;
    order += std::to_string(unit_1->get_id()) + " ";
    order += "A ";
    order += std::to_string(unit_2->get_id());
    order += "\n";
    orders.push_back(order);
    unit_2->set_stamina(unit_2->get_stamina() - damage_inflicited(unit_1->get_type_of_unit(),unit_2->get_type_of_unit()));
    if(unit_2->get_stamina() < 1){
        if(unit_2->get_type_of_unit() == Type_of_unit::BASE){
            unit_2->set_stamina(0);
        }else{
            game_state.remove_unit_by_id(unit_2->get_id());
            enemy_units = game_state.find_all_units(Ownership::ENEMIES);
        }
        
    }

}

/**
 * @brief Creates a new unit of the specified type.
 * 
 * This function creates a string order to build a new unit of the specified 
 * type at the player's base. The order string is then added to the list of orders.
 *
 * @param unit The type of the unit to be created.
 */

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
/**
 * @brief Calculates the number of given units relative to the total number of units.
 * 
 * This function returns the number of given units as a proportion of the total 
 * number of units (both the player's and enemy's units). If there are no units 
 * in total, it returns 0.
 *
 * @param units A vector of pointers to the units.
 * @return The number of given units relative to the total number of units.
 */

double Commander::number_of_units_relatively(std::vector<Unit *> units){
    
    if(my_units.size() == 0 && enemy_units.size() == 0){
        return 0;
    }else{
        return static_cast<double>(units.size()) / (my_units.size() + enemy_units.size());
    }
}

/**
 * @brief Executes the initial game phase strategy for the commander's units.
 *
 * This method manages the initial game phase for a player, which includes the creation of units,
 * execution of attack and defense strategies, and movements of units on the map. The method is
 * based on the current state of the game and the commander's resources. It is split into two 
 * scenarios, one when there are mines on the map, and another when there are none.
 *
 * @note This method takes into account a variety of factors like the average stamina, speed, 
 * attack range of units, and the number of turns. It also performs multi-threaded operations 
 * for the movement of multiple units.
 *
 * @details The method is broken down into several steps:
 * - Calculating averages of unit characteristics
 * - If mines are available, nearest mines are determined
 * - Depending on the turn amount, units are created and gold is deducted accordingly
 * - The attack capability of units is checked and attacks are performed if conditions are met
 * - Units are moved to either mines or base, depending on certain conditions
 * - In the absence of mines, the method handles unit creation, attacks, and movements differently
 *
 * @throws std::runtime_error if there are not enough resources to create units.
 *
 * @see base_with_more_stamina(), average_unit_stamina(), average_unit_speed(), 
 * average_unit_attack_range(), what_can_i_build(), create_unit(), attack_unit(), move_unit()
 *
 */

void Commander::initial_game_phase(){
    int base_more_stamina = base_with_more_stamina();

    if(mines.size() > 0){
        auto nearest_mine_from_my_base = std::min_element(mines.begin(), mines.end(), 
                                        [this](Coordinartes mine_1, Coordinartes mine_2)
                                        {return this->game_state.distance_between_units(mine_1,this->my_base) < this->game_state.distance_between_units(mine_2,this->my_base);});

        /*start of the game*/

           if(enemie_forces_analysis.turn_amount() < 2){
            if(!my_base->is_under_construction()){
                create_unit(Type_of_unit::WORKER);
                game_state.gold_amount -= Worker::_cost;
            }
            }else if(enemie_forces_analysis.turn_amount() >= 2 && enemie_forces_analysis.turn_amount() < 100){
            /*ten blok decyduje jakie zakupić jednostki na początek gry */

                int count = std::count_if(my_units.begin(),my_units.end(),[](Unit *unit){return unit->get_type_of_unit() == Type_of_unit::WORKER;});
                if(count % 3 != 0 ){
                    if(!my_base->is_under_construction() && game_state.gold_amount >= Worker::_cost){
                        create_unit(Type_of_unit::WORKER);
                        game_state.gold_amount -= Worker::_cost;
                    }
                }else{
                    if(!my_base->is_under_construction()){
                        auto units_i_can_build = what_can_i_build();
                        auto unit_to_build = std::find(units_i_can_build.begin(),units_i_can_build.end(),Type_of_unit::KNIGHT);
                        if(*unit_to_build == Type_of_unit::KNIGHT){
                                create_unit(Type_of_unit::KNIGHT);
                                game_state.gold_amount -= Knight::_cost;
                        }else{
                            unit_to_build = std::find(units_i_can_build.begin(),units_i_can_build.end(),Type_of_unit::SWORDSMAN);
                            if(*unit_to_build == Type_of_unit::SWORDSMAN){
                                    create_unit(Type_of_unit::SWORDSMAN);
                                    game_state.gold_amount -= Swordsman::_cost;
                            }else{
                                unit_to_build = std::find(units_i_can_build.begin(),units_i_can_build.end(),Type_of_unit::WORKER);
                                    create_unit(Type_of_unit::WORKER);
                                    game_state.gold_amount -= Worker::_cost;
                            }
                        }
                    }
                }

                /*sprawdzanie możliwości ataku*/
                for(int i = 0; i < my_units.size(); ++i){ // czy mogę atakować bazę przeciwnika
                    if(game_state.is_enemy_within_attack_range(my_units[i],enemy_base)){
                        if(enemy_base->get_stamina() > 0){
                        attack_unit(my_units[i],enemy_base);
                        my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                        break;
                        }
                    }
                    for(int j = 0; j < enemy_units.size(); ++j){
                        if(game_state.is_enemy_within_attack_range(my_units[i],enemy_units[j])){
                            if(who_will_win_skirmish(my_units[i],enemy_units[j]) == Ownership::MINE){ // simulating who is likely to win
                                attack_unit(my_units[i],enemy_units[j]);
                                my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                                break;
                            }
                        }
                    }
                }

                

                /*wysyłaine jednostek w odpowiednie miejsca*/
                int enemy_units_aorund_my_base = percent_of_units_around_base(my_base,enemy_units,(game_state.map.size() + game_state.map[0].size()) * 0.25 / 2);
                if(base_more_stamina - (static_cast<double>(enemy_units_aorund_my_base) * 0.3) > 0 ){
                    for(int i = 0; i < my_units.size(); ++i){
                        threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], *nearest_mine_from_my_base, my_units[i]->get_speed()));     
                    }
                }else{
                   for(int i = 0; i < my_units.size(); ++i){
                        threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(my_base), my_units[i]->get_speed()));     
                   } 
                }
                for(int i = 0; i < threads.size(); ++i){
                   threads[i].join();
                }
          }
    }else{ // brak kopalni na mapie 
        if(enemie_forces_analysis.turn_amount() > 0 && enemie_forces_analysis.turn_amount() < 100){
            if(!my_base->is_under_construction()){
                auto units_i_can_build = what_can_i_build();
                auto unit_to_build = std::find(units_i_can_build.begin(),units_i_can_build.end(),Type_of_unit::KNIGHT);
                if(*unit_to_build == Type_of_unit::KNIGHT){
                        create_unit(Type_of_unit::KNIGHT);
                        game_state.gold_amount -= Knight::_cost;
                }else{
                    unit_to_build = std::find(units_i_can_build.begin(),units_i_can_build.end(),Type_of_unit::SWORDSMAN);
                    if(*unit_to_build == Type_of_unit::SWORDSMAN){
                            create_unit(Type_of_unit::SWORDSMAN);
                            game_state.gold_amount -= Swordsman::_cost;
                    }else{
                        unit_to_build = std::find(units_i_can_build.begin(),units_i_can_build.end(),Type_of_unit::PIKEMAN);
                        if(*unit_to_build == Type_of_unit::PIKEMAN){
                            create_unit(Type_of_unit::PIKEMAN);
                            game_state.gold_amount -= Pikeman::_cost;
                        }
                    }
                }
            }
            /*sprawdzanie możliwości ataku*/
                for(int i = 0; i < my_units.size(); ++i){ // czy mogę atakować bazę przeciwnika
                    if(game_state.is_enemy_within_attack_range(my_units[i],enemy_base)){
                        if(enemy_base->get_stamina() > 0){
                        attack_unit(my_units[i],enemy_base);
                        my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                        break;
                        }
                    }
                    for(int j = 0; j < enemy_units.size(); ++j){
                        if(game_state.is_enemy_within_attack_range(my_units[i],enemy_units[j])){
                            if(who_will_win_skirmish(my_units[i],enemy_units[j]) == Ownership::MINE){ // simulating who is likely to win
                                attack_unit(my_units[i],enemy_units[j]);
                                my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                                break;
                            }
                        }
                    }
                }
                 /*wysyłaine jednostek w odpowiednie miejsca*/
                int enemy_units_aorund_my_base = percent_of_units_around_base(my_base,enemy_units,(game_state.map.size() + game_state.map[0].size()) * 0.25 / 2);
                if(base_more_stamina - (static_cast<double>(enemy_units_aorund_my_base) * 0.3) > 0 ){
                    for(int i = 0; i < my_units.size(); ++i){
                        threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                    }
                }else{
                   for(int i = 0; i < my_units.size(); ++i){
                        if(my_units[i]->get_type_of_unit() != Type_of_unit::WORKER){
                                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                            }
                   } 
                }
                for(int i = 0; i < threads.size(); ++i){
                   threads[i].join();
                }

        }
    }
}
/**
 * @brief Executes the mid-game strategy of the game , handling actions related to units' creation, movement, and attack.
 *
 * The function calculates various statistical values like enemy base stamina difference, average speed, attack range, etc.
 * Depending on these calculations, decisions are made to create specific type of units (Workers, Knights, Pikemen, Swordsmen, Archers)
 * If enemy base is within the attack range of any of the units, a check is made whether the enemy base stamina is more than zero and attacks accordingly.
 * Also checks if the enemy unit is within attack range, a simulated skirmish is conducted and if the result is favorable, attack is made on the enemy unit.
 * Movement of units is also handled in this function. Workers are directed to move towards the nearest mine. Other units move towards the enemy base.
 * Threads are created for the movement of each unit and joined subsequently to ensure that all movements are complete before the function exits.
 *
 */

void Commander::middle_game_phase(){
    int base_more_stamina = base_with_more_stamina();
   

    if(enemie_forces_analysis.turn_amount() >= 100  && enemie_forces_analysis.turn_amount() < 700){
        auto enemy_base_stamina_diff = enemie_forces_analysis.base_stamina_diff(50);
        auto enemy_num_of_units_relatively_diff = enemie_forces_analysis.number_of_units_relatively_diff(50);
        auto enemy_avr_stamina_diff = enemie_forces_analysis.avr_stamina_diff(50);
        auto enemy_avr_speed_diff = enemie_forces_analysis.avr_speed_diff(50);
        auto enemy_avr_attack_range_diff = enemie_forces_analysis.avr_attack_range_diff(50);
        int enemy_base_stamina_diff_val = std::count_if(enemy_base_stamina_diff.begin(),
                                                        enemy_base_stamina_diff.end(),
                                                        [](int diff_val){return diff_val < 0;});

        if(enemy_base_stamina_diff_val / enemy_base_stamina_diff.size() > 60){ // w 60% ostatnich 50 tur zadałem uszkodzenia bazie przeciwnika
            auto what_can_i_buy= what_can_i_build();
            auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::WORKER);
            if(number_of_units_relatively(my_units) > 50 || my_units.size() % 10 != 0){
                if(!my_base->is_under_construction()){
                    if(*unit == Type_of_unit::WORKER){
                        create_unit(Type_of_unit::WORKER);
                        game_state.gold_amount -= Worker::_cost;
                    }
                }
            }else{
                int avr_enemies_speed = average_unit_speed(enemy_units);
                if(avr_enemies_speed >  3){
                    if(!my_base->is_under_construction()){
                        auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::KNIGHT);
                        if(*unit == Type_of_unit::KNIGHT){
                            create_unit(Type_of_unit::KNIGHT);
                            game_state.gold_amount -= Knight::_cost;
                        }else{
                            auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::PIKEMAN);
                            if(*unit == Type_of_unit::PIKEMAN){
                                create_unit(Type_of_unit::PIKEMAN);
                                game_state.gold_amount -= Pikeman::_cost;
                            }else{
                                auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::ARCHER);
                                if(*unit == Type_of_unit::ARCHER){
                                    create_unit(Type_of_unit::ARCHER);
                                    game_state.gold_amount -= Archer::_cost;
                                }
                            }
                        }
                    }
                }else{
                    if(!my_base->is_under_construction()){
                        auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::KNIGHT);
                        if(*unit == Type_of_unit::KNIGHT){
                            create_unit(Type_of_unit::KNIGHT);
                            game_state.gold_amount -= Knight::_cost;
                        }else{
                            auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::PIKEMAN);
                            if(*unit == Type_of_unit::SWORDSMAN){
                                create_unit(Type_of_unit::SWORDSMAN);
                                game_state.gold_amount -= Swordsman::_cost;
                            }else{
                                auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::ARCHER);
                                if(*unit == Type_of_unit::ARCHER){
                                    create_unit(Type_of_unit::ARCHER);
                                    game_state.gold_amount -= Archer::_cost;
                                }
                            }
                        }
                    }
                }
            }
        }else{
            auto what_can_i_buy= what_can_i_build();
            if(!my_base->is_under_construction()){
                auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::KNIGHT);
                if(*unit == Type_of_unit::KNIGHT){
                    create_unit(Type_of_unit::KNIGHT);
                    game_state.gold_amount -= Knight::_cost;
                
                }else{
                    auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::SWORDSMAN);
                    if(*unit == Type_of_unit::SWORDSMAN){
                        create_unit(Type_of_unit::SWORDSMAN);
                        game_state.gold_amount -= Swordsman::_cost;
                    }else{
                        auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::PIKEMAN);
                        if(*unit == Type_of_unit::PIKEMAN){
                            create_unit(Type_of_unit::PIKEMAN);
                            game_state.gold_amount -= Pikeman::_cost;
                        }else{
                            auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::ARCHER);
                            if(*unit == Type_of_unit::ARCHER){
                                create_unit(Type_of_unit::ARCHER);
                                game_state.gold_amount -= Archer::_cost;
                            }
                        }
                    }   
                }
            }
        }

        for(int i = 0; i < my_units.size(); ++i){ // czy mogę atakować bazę przeciwnika
            if(game_state.is_enemy_within_attack_range(my_units[i],enemy_base)){
                if(enemy_base->get_stamina() > 0){
                attack_unit(my_units[i],enemy_base);
                my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                break;
                }
            }
            for(int j = 0; j < enemy_units.size(); ++j){
                if(game_state.is_enemy_within_attack_range(my_units[i],enemy_units[j])){
                    if(who_will_win_skirmish(my_units[i],enemy_units[j]) == Ownership::MINE){ // simulating who is likely to win
                        attack_unit(my_units[i],enemy_units[j]);
                        my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                        break;
                    }
                }
            }
        }

        if(mines.size() > 0){
            auto nearest_mine_from_my_base = std::min_element(mines.begin(), mines.end(), 
                                        [this](Coordinartes mine_1, Coordinartes mine_2)
                                        {return this->game_state.distance_between_units(mine_1,this->my_base) < this->game_state.distance_between_units(mine_2,this->my_base);});
            int enemy_units_aorund_my_base = percent_of_units_around_base(my_base,enemy_units,(game_state.map.size() + game_state.map[0].size()) * 0.25 / 2);
                if(base_more_stamina - (static_cast<double>(enemy_units_aorund_my_base) * 0.3) > 0 ){
                    for(int i = 0; i < my_units.size(); ++i){
                        if(my_units[i]->get_type_of_unit() == Type_of_unit::WORKER){
                            threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], *nearest_mine_from_my_base, my_units[i]->get_speed()));     
                        }else{
                            if(game_state.distance_between_units(*nearest_mine_from_my_base, my_units[i]) > 3){
                                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                            }else{
                                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], *nearest_mine_from_my_base, my_units[i]->get_speed()));     
                            }
                        }
                    }
                }else{
                   for(int i = 0; i < my_units.size(); ++i){
                        if(my_units[i]->get_type_of_unit() != Type_of_unit::WORKER){
                            threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(my_base), my_units[i]->get_speed()));     
                        }
                   } 
                }
                for(int i = 0; i < threads.size(); ++i){
                   threads[i].join();
                }

        }else{
            int enemy_units_aorund_my_base = percent_of_units_around_base(my_base,enemy_units,(game_state.map.size() + game_state.map[0].size()) * 0.25 / 2);
                if(base_more_stamina - (static_cast<double>(enemy_units_aorund_my_base) * 0.3) > 0 ){
                    for(int i = 0; i < my_units.size(); ++i){
                        if(my_units[i]->get_type_of_unit() == Type_of_unit::WORKER){
                            threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                        }else{
                            threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                        }
                    }
                }else{
                   for(int i = 0; i < my_units.size(); ++i){
                        threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                   } 
                }
                for(int i = 0; i < threads.size(); ++i){
                   threads[i].join();
                }
        }                                  

    }
}
/**
 * @brief Executes the final phase of the game, making strategic decisions based on current game state.
 *
 * This method handles decision making during the final phase of the game, analyzing enemy forces, 
 * deciding what units to create, whether to attack or defend, and managing unit movement. These decisions 
 * are based on a variety of factors, such as the strength and size of enemy forces, the number of turns passed, 
 * and the amount of resources available. 
 *
 * This method should be called each turn during the final phase of the game.
 *
 * @note This method does not return any value.
 */

void Commander::final_game_phase(){
    int base_more_stamina = base_with_more_stamina();
    if(enemie_forces_analysis.turn_amount() >= 700){
        auto enemy_base_stamina_diff = enemie_forces_analysis.base_stamina_diff(50);
        auto enemy_num_of_units_relatively_diff = enemie_forces_analysis.number_of_units_relatively_diff(50);
        auto enemy_avr_stamina_diff = enemie_forces_analysis.avr_stamina_diff(50);
        auto enemy_avr_speed_diff = enemie_forces_analysis.avr_speed_diff(50);
        auto enemy_avr_attack_range_diff = enemie_forces_analysis.avr_attack_range_diff(50);
        auto what_can_i_buy= what_can_i_build();
        int enemy_base_stamina_diff_val = std::count_if(enemy_base_stamina_diff.begin(),
                                                        enemy_base_stamina_diff.end(),
                                                        [](int diff_val){return diff_val < 0;});
        if(enemy_base_stamina_diff_val / enemy_base_stamina_diff.size() > 60){ // w 60% ostatnich 50 tur zadałem uszkodzenia bazie przeciwnika

            
            if(!my_base->is_under_construction()){
                if(my_units.size() % 10 != 0){
                    auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::CATAPULT);
                    if(*unit == Type_of_unit::CATAPULT){
                        create_unit(Type_of_unit::CATAPULT);
                        game_state.gold_amount -= Catapult::_cost;
                    }else{
                        auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::RAM);
                        if(*unit == Type_of_unit::RAM){
                            create_unit(Type_of_unit::RAM);
                            game_state.gold_amount -= Ram::_cost;
                        }else{
                            auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::KNIGHT);
                            if(*unit == Type_of_unit::KNIGHT){
                                create_unit(Type_of_unit::KNIGHT);
                                game_state.gold_amount -= Knight::_cost;
                            }else{
                                auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::SWORDSMAN);
                                if(*unit == Type_of_unit::SWORDSMAN){
                                    create_unit(Type_of_unit::SWORDSMAN);
                                    game_state.gold_amount -= Swordsman::_cost;
                                }else{
                                    auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::PIKEMAN);
                                    if(*unit == Type_of_unit::PIKEMAN){
                                        create_unit(Type_of_unit::PIKEMAN);
                                        game_state.gold_amount -= Pikeman::_cost;
                                    }else{
                                        auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::ARCHER);
                                        if(*unit == Type_of_unit::ARCHER){
                                            create_unit(Type_of_unit::ARCHER);
                                            game_state.gold_amount -= Archer::_cost;
                                        }
                                    }
                                }
                            }
                        }   
                    }
                }else{
                    auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::WORKER);
                    if(*unit == Type_of_unit::WORKER){
                        create_unit(Type_of_unit::WORKER);
                        game_state.gold_amount -= Worker::_cost;
                    }
                }       
            }
        }else{
               if(!my_base->is_under_construction()){
                    auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::KNIGHT);
                    if(*unit == Type_of_unit::KNIGHT){
                        create_unit(Type_of_unit::KNIGHT);
                        game_state.gold_amount -= Knight::_cost;
                    }else{
                        auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::SWORDSMAN);
                        if(*unit == Type_of_unit::SWORDSMAN){
                            create_unit(Type_of_unit::SWORDSMAN);
                            game_state.gold_amount -= Swordsman::_cost;
                        }else{
                            auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::PIKEMAN);
                            if(*unit == Type_of_unit::PIKEMAN){
                                create_unit(Type_of_unit::PIKEMAN);
                                game_state.gold_amount -= Pikeman::_cost;
                            }else{
                                auto unit = std::find(what_can_i_buy.begin(), what_can_i_buy.end(), Type_of_unit::ARCHER);
                                if(*unit == Type_of_unit::ARCHER){
                                    create_unit(Type_of_unit::ARCHER);
                                    game_state.gold_amount -= Archer::_cost;
                                }
                            }
                        }
                    }
                } 
            }

            for(int i = 0; i < my_units.size(); ++i){ // czy mogę atakować bazę przeciwnika
            if(game_state.is_enemy_within_attack_range(my_units[i],enemy_base)){
                if(enemy_base->get_stamina() > 0){
                attack_unit(my_units[i],enemy_base);
                my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                break;
                }
            }
            for(int j = 0; j < enemy_units.size(); ++j){
                if(game_state.is_enemy_within_attack_range(my_units[i],enemy_units[j])){
                    if(who_will_win_skirmish(my_units[i],enemy_units[j]) == Ownership::MINE){ // simulating who is likely to win
                        attack_unit(my_units[i],enemy_units[j]);
                        my_units[i]->set_speed(my_units[i]->get_speed() - 1); //cost of attack; one speed
                        break;
                    }
                }
            }
        }
         if(mines.size() > 0){
            auto nearest_mine_from_my_base = std::min_element(mines.begin(), mines.end(), 
                                        [this](Coordinartes mine_1, Coordinartes mine_2)
                                        {return this->game_state.distance_between_units(mine_1,this->my_base) < this->game_state.distance_between_units(mine_2,this->my_base);});
            int enemy_units_aorund_my_base = percent_of_units_around_base(my_base,enemy_units,(game_state.map.size() + game_state.map[0].size()) * 0.25 / 2);
                if(base_more_stamina - (static_cast<double>(enemy_units_aorund_my_base) * 0.3) > 0 ){
                    for(int i = 0; i < my_units.size(); ++i){
                        if(my_units[i]->get_type_of_unit() == Type_of_unit::WORKER){
                            threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], *nearest_mine_from_my_base, my_units[i]->get_speed()));     
                        }else{
                            if(game_state.distance_between_units(*nearest_mine_from_my_base, my_units[i]) > 3){
                                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                            }else{
                                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], *nearest_mine_from_my_base, my_units[i]->get_speed()));     
                            }
                        }
                    }
                }else{
                   for(int i = 0; i < my_units.size(); ++i){
                        if(my_units[i]->get_type_of_unit() != Type_of_unit::WORKER){
                                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                            }
                   } 
                }
                for(int i = 0; i < threads.size(); ++i){
                   threads[i].join();
                }

        }else{
            int enemy_units_aorund_my_base = percent_of_units_around_base(my_base,enemy_units,(game_state.map.size() + game_state.map[0].size()) * 0.25 / 2);
                if(base_more_stamina - (static_cast<double>(enemy_units_aorund_my_base) * 0.3) > 0 ){
                    for(int i = 0; i < my_units.size(); ++i){
                        if(my_units[i]->get_type_of_unit() == Type_of_unit::WORKER){
                            threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                        }else{
                            if(my_units[i]->get_type_of_unit() != Type_of_unit::WORKER){
                                threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(enemy_base), my_units[i]->get_speed()));     
                            }
                        }
                    }
                }else{
                   for(int i = 0; i < my_units.size(); ++i){
                        threads.push_back(std::thread(&Commander::move_unit, this, my_units[i], game_state.get_coordinate_by_id(my_base), my_units[i]->get_speed()));     
                   } 
                }
                for(int i = 0; i < threads.size(); ++i){
                   threads[i].join();
                }
        }     

    }
}


/**
 * @brief Function to process and issue orders to units based on game state.
 *
 * This function analyzes the current game state and makes strategic decisions to control units.
 * Depending on the game state, it might create new units, move existing ones or order them to attack. 
 * The issued orders are saved to a file.
 * 
 * @param filename The name of the file where the orders will be saved.
 */

void Commander::give_orders(const char *filename){
    initial_game_phase();
    middle_game_phase();
    final_game_phase();

    
    File_parser::save_enemie_forces({
        0,
        enemy_base->get_stamina(),
        number_of_units_relatively(enemy_units),
        average_unit_stamina(enemy_units),
        average_unit_speed(enemy_units),
        average_unit_attack_range(enemy_units)
    });

    File_parser::save_orders(filename,orders);

}


/**
 * @brief Destroy the Commander:: Commander object
 * 
 */

Commander::~Commander(){
    game_state.clear_map();
}

