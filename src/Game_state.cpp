#include "Game_state.hpp"

/**
 * @brief Construct a new Game_state::Game_state object
 * 
 */

Game_state::Game_state(){};

/**
 * @brief Find the base owned by a given player.
 * @param ownership The ownership for which to find the base.
 * @return Pointer to the Unit representing the base, or nullptr if not found.
 */

Unit *Game_state::find_base(Ownership ownership){
    
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            for(int k = 0; k < map[i][j].units.size(); ++k){
                if(map[i][j].units[k]->get_type_of_unit() == Type_of_unit::BASE && map[i][j].units[k]->get_ownership() == ownership){
                    return map[i][j].units[k];
                }
            }
        }
    }
    return nullptr;
}

/**
 * @brief Find all units owned by a given player.
 * @param ownership The ownership for which to find the units.
 * @return A vector of pointers to the Units found.
 */
std::vector<Unit *> Game_state::find_all_units(Ownership ownership){
    
    std::vector<Unit *> units; 
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            for(int k = 0; k < map[i][j].units.size(); ++k){
                if(map[i][j].units[k]->get_type_of_unit() != Type_of_unit::BASE && map[i][j].units[k]->get_ownership() == ownership){
                    units.push_back(map[i][j].units[k]);
                }
            }
        }
    }
    return units;
}

/**
 * @brief Get the coordinates of a given unit.
 * @param unit The unit for which to get the coordinates.
 * @return The Coordinates of the unit, or {-1,-1} if not found.
 */

Coordinartes Game_state::get_coordinate_by_id(Unit *unit){

    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            for(int k = 0; k < map[i][j].units.size(); ++k){
                if(map[i][j].units[k]->get_id() == unit->get_id()){
                    return{i,j};
                }
            }
        }
    }
    return {-1,-1};
}

/**
 * @brief Calculate the  distance between two units.
 * @param unit_1 The first unit.
 * @param unit_2 The second unit.
 * @return The  distance between the units.
 */

int Game_state::distance_between_units(Unit *unit_1, Unit *unit_2){
    Coordinartes cord_unit1, cord_unit2;
    cord_unit1 = get_coordinate_by_id(unit_1);
    cord_unit2 = get_coordinate_by_id(unit_2);
    return std::abs(cord_unit1.x - cord_unit2.x) + std::abs(cord_unit1.y - cord_unit2.y);
}

/**
 * @brief Check if an enemy unit is within attack range of a given unit.
 * @param my_unit The unit to check from.
 * @param enemy_unit The unit to check against.
 * @return true if the enemy is within range, false otherwise.
 */

bool Game_state::is_enemy_within_attack_range(Unit *my_unit, Unit *enemy_unit){

    int distance = distance_between_units(my_unit,enemy_unit);
    if(distance > my_unit->get_attack_range()){
        return false;
    }else{
        return true;
    }
}

/**
 * @brief Destroy the Game_state::Game_state object
 * 
 */

Game_state::~Game_state(){};
