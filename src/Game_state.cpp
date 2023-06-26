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
 * @brief Function to locate all mines in the game map.
 * 
 * This function scans the entire game map for mines and stores the coordinates of each mine found
 * in a vector. The map is a 2D vector of 'Map_field' enum type, which contains 'MINE' as one of its
 * enum value to represent a mine in the game.
 *
 * @return std::vector<Coordinates> A vector containing the coordinates of all mines found in the game map.
 * Each coordinate is a pair of integers where the first integer is the X coordinate (column index) and 
 * the second integer is the Y coordinate (row index).
 */

std::vector<Coordinartes> Game_state::find_mines(){
    
    std::vector<Coordinartes> mines;
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            if(map[i][j].map_filed == Map_field::MINE){
                mines.push_back({j,i});
            }
        }
    }
    return mines;
}



/**
 * @brief Find all units owned by a given player, does not return the base.
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
                    return{j,i};
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
 * @brief Calculates  distance between a unit identified by its coordinates and another unit.
 * @param cord_unit_1 Coordinates of the first unit.
 * @param unit_2 Pointer to the second unit.
 * @return The distance between the two units.
 */

int Game_state::distance_between_units(Coordinartes cord_unit_1, Unit *unit_2){

    Coordinartes cord_unit2;    
    cord_unit2 = get_coordinate_by_id(unit_2);
    return std::abs(cord_unit_1.x - cord_unit2.x) + std::abs(cord_unit_1.y - cord_unit2.y);

}

/**
 * @brief Calculates the  distance between two units, both identified by their coordinates.
 * @param cord_unit_1 Coordinates of the first unit.
 * @param cord_unit_2 Coordinates of the second unit.
 * @return The distance between the two units.
 */
int Game_state::distance_between_units(Coordinartes cord_unit_1, Coordinartes cord_unit_2){

    return std::abs(cord_unit_1.x - cord_unit_2.x) + std::abs(cord_unit_1.y - cord_unit_2.y);
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
 * @brief Removes a unit identified by its ID from the game state's map.
 * 
 * This function traverses the map to find and remove the unit with the specified ID.
 * After finding the unit, it deletes the unit from memory and removes the pointer from the vector.
 * 
 * @param id The unique ID of the unit to be removed.
 */

void Game_state::remove_unit_by_id(int id){

     for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            for(int k = 0; k < map[i][j].units.size(); ++k){
                if(map[i][j].units[k]->get_id() == id){
                    auto unit = map[i][j].units.begin() + k;
                    delete *unit;
                    map[i][j].units.erase(unit);
                    break;
                    
                }
            }
        }
    }
}

void Game_state::clear_map(){
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            for(int k = 0; k < map[i][j].units.size(); ++k){
                delete map[i][j].units[k];
            }
            map[i][j].units.clear();
        }
    }
}
/**
 * @brief Destroy the Game_state::Game_state object
 * 
 */

Game_state::~Game_state(){};


