#include "Floodfill.hpp"

/**
 * @brief Constructs a Floodfill object from a given map.
 * 
 * The constructor creates a Floodfill object, initializes it with a given map (`_map`) 
 * which contains units and obstacles. It then builds a simplified version of this map (`map`) 
 * which only contains information about obstacles and free spaces.
 *
 * The constructor iterates through the given map, checking each field:
 * - If the field on `map_with_units` is an obstacle, the corresponding field on `map` is marked as an obstacle.
 * - If the field on `map_with_units` is free, it then checks if there are any units present:
 *   - If there are enemy units, the corresponding field on `map` is marked as an obstacle.
 *   - If there are no units or the units are not enemies, the corresponding field on `map` is marked as free.
 * 
 * The resulting `map` represents the game field where free spaces and enemy occupied spaces are distinguished.
 * 
 * @param _map A 2D vector representing the game map with units and obstacles.
 */


Floodfill::Floodfill(const Map_table _map): map_with_units(_map){
    map_width = map_with_units[0].size();
    map_height = map_with_units.size();
    map.resize(map_height,std::vector<Floodfill_filed>(map_width)); // creation of a map containing only 
                                                                    //information about free and occupied 
                                                                    //fields on the basis of a map containing all information
    for(int i = 0; i < map_with_units.size(); ++i){
        for(int j = 0; j < map_with_units[i].size(); ++j){
            if(map_with_units[i][j].map_filed == Map_field::OBSTACLE){
                map[i][j].field = Map_field::OBSTACLE;
            }else if(map_with_units[i][j].map_filed == Map_field::FREE || map_with_units[i][j].map_filed == Map_field::MINE ){
                if(!map_with_units[i][j].units.empty()){
                    if(map_with_units[i][j].units.front()->get_ownership() == Ownership::ENEMIES){
                        map[i][j].field = Map_field::OBSTACLE;
                    }else{
                        map[i][j].field = Map_field::FREE;
                    }
                }else{
                    map[i][j].field = Map_field::FREE;
                }
            }
        } 
    }
}


void Floodfill::update_map(Map_table _map){
    map_with_units = _map;
    for(int i = 0; i < map.size(); ++i){
        map[i].clear();
    }
    map.clear();

    map_width = map_with_units[0].size();
    map_height = map_with_units.size();
    map.resize(map_height,std::vector<Floodfill_filed>(map_width)); // creation of a map containing only 
                                                                    //information about free and occupied 
                                                                    //fields on the basis of a map containing all information
    for(int i = 0; i < map_with_units.size(); ++i){
        for(int j = 0; j < map_with_units[i].size(); ++j){
            if(map_with_units[i][j].map_filed == Map_field::OBSTACLE){
                map[i][j].field = Map_field::OBSTACLE;
            }else if(map_with_units[i][j].map_filed == Map_field::FREE || map_with_units[i][j].map_filed == Map_field::MINE ){
                if(!map_with_units[i][j].units.empty()){
                    if(map_with_units[i][j].units.front()->get_ownership() == Ownership::ENEMIES){
                        map[i][j].field = Map_field::OBSTACLE;
                    }else{
                        map[i][j].field = Map_field::FREE;
                    }
                }else{
                    map[i][j].field = Map_field::FREE;
                }
            }
        } 
    }
}

/**
 * @brief Returns a vector of neighbouring Coordinates.
 *
 * This function returns all valid neighbouring fields (up, down, left, right and diagonally) for a given
 * set of Coordinates, considering the boundaries of the game field.
 * 
 * @param xy The Coordinates of interest.
 * @return A vector of Coordinates representing the neighbouring fields.
 */

std::vector<Coordinartes> Floodfill::get_neighbouring_fields(Coordinartes xy){
    std::vector<int> dx = {-1, -1, -1,  0, 0,  1, 1, 1};
    std::vector<int> dy = {-1,  0,  1, -1, 1, -1, 0, 1};
    Coordinartes new_coord;
    std::vector<Coordinartes> neighbours;
    for(int i = 0; i < 8; ++i) {
        new_coord.x = xy.x + dx[i];
        new_coord.y = xy.y + dy[i];
        if(new_coord.x >= 0 && new_coord.x < map_width && new_coord.y >= 0 && new_coord.y < map_height){
            if(map[new_coord.y][new_coord.x].field != Map_field::OBSTACLE && map[new_coord.y][new_coord.x].floodfill_value == INT_MAX){
                neighbours.push_back(new_coord);
            }
        }
    }
    return neighbours;
}


/**
 * @brief Checks if a target Coordinate is a neighbour of the current Coordinate.
 *
 * This function checks all valid neighbouring fields (up, down, left, right and diagonally) of the current
 * Coordinates and returns true if the target Coordinates is a neighbour.
 * 
 * @param current The current Coordinates.
 * @param target The target Coordinates.
 * @return True if the target is a neighbour of the current Coordinates, false otherwise.
 */

bool Floodfill::is_target_neighbour(Coordinartes current, Coordinartes target){
    std::vector<int> dx = {-1, -1, -1,  0, 0,  1, 1, 1};
    std::vector<int> dy = {-1,  0,  1, -1, 1, -1, 0, 1};
    Coordinartes new_coord;
    std::vector<Coordinartes> neighbours;
    for(int i = 0; i < 8; ++i) {
        new_coord.x = current.x + dx[i];
        new_coord.y = current.y + dy[i];
        if(new_coord.x >= 0 && new_coord.x < map_width && new_coord.y >= 0 && new_coord.y < map_height){
            if(new_coord == target){
                return true;
            }
        }
    }
    return false;

}


/**
 * @brief Returns the neighbouring Coordinates with the smallest floodfill value.
 *
 * This function checks all valid neighbouring fields (up, down, left, right and diagonally) of the given
 * Coordinates and returns the Coordinates with the smallest floodfill value.
 * 
 * @param xy The Coordinates of interest.
 * @return The Coordinates of the neighbouring field with the smallest floodfill value.
 */

Coordinartes Floodfill::neighbour_with_the_smallest_value(Coordinartes xy){
    std::vector<int> dx = {-1, -1, -1,  0, 0,  1, 1, 1};
    std::vector<int> dy = {-1,  0,  1, -1, 1, -1, 0, 1};
    Coordinartes new_coord;
    std::vector<Coordinartes>  min_coord;
    std::vector<int> values;
    std::vector<Floodfill_filed> neighbours;
    for(int i = 0; i < 8; ++i) {
        new_coord.x = xy.x + dx[i];
        new_coord.y = xy.y + dy[i];
        if(new_coord.x >= 0 && new_coord.x < map_width && new_coord.y >= 0 && new_coord.y < map_height){
            values.push_back(map[new_coord.y][new_coord.x].floodfill_value);
            min_coord.push_back(new_coord);
        }
    }
    auto min_elem = std::min_element(values.begin(),values.end());
    int index = std::distance(values.begin(),min_elem);
    return min_coord[index];
}

bool Floodfill::is_filed_free(Coordinartes xy){
    if(map[xy.y][xy.x].field == Map_field::FREE){
        return true;
    }else{
        return false;
    }
}


/**
 * @brief Conducts the floodfill algorithm from a start Coordinate to a target Coordinate.
 *
 * This function implements the floodfill algorithm to mark each accessible field on the game map 
 * with a value representing its distance from the start Coordinate. The function ends when the 
 * target Coordinate is reached or the queue of Coordinates is empty (all reachable fields have been visited).
 * 
 * @param from The start Coordinates.
 * @param to The target Coordinates.
 */

void Floodfill::floodfill(const Coordinartes &from, const Coordinartes &to){
    int curent_val = 0;
    std::queue<Coordinartes> queue;
    Coordinartes current_coord = from;
    map[current_coord.y][current_coord.x].floodfill_value = curent_val;
    queue.push(from);
    while(!queue.empty()){
        current_coord = queue.front(); 
        queue.pop();
        curent_val = map[current_coord.y][current_coord.x].floodfill_value;
        if(is_target_neighbour(current_coord, to)) {
            break;
        }
        auto neighbours = get_neighbouring_fields(current_coord);
        for(int i = 0; i < neighbours.size(); ++i){
            map[neighbours[i].y][neighbours[i].x].floodfill_value = curent_val + 1;
            queue.push(neighbours[i]);
        }
    }
} 

/**
 * @brief Returns the shortest path from a start Coordinate to a target Coordinate.
 *
 * This function returns a vector of Coordinates which represents the shortest path from a start
 * Coordinate to a target Coordinate based on the floodfill values assigned to each field.
 * The path is given as a sequence of Coordinates from the start to the target.
 * 
 * @param from The start Coordinates.
 * @param to The target Coordinates.
 * @return A vector of Coordinates representing the shortest path from the start to the target.
 */

std::vector<Coordinartes> Floodfill::get_path(const Coordinartes &from, const Coordinartes &to) {
    std::vector<Coordinartes> path;
    Coordinartes current_coord = to;
    while(map[current_coord.y][current_coord.x].floodfill_value != 0){
        current_coord = neighbour_with_the_smallest_value(current_coord);
        path.push_back(current_coord);
    }
    std::reverse(path.begin(),path.end());
    return path;
}
  
/**
 * @brief Destroy the Floodfill:: Floodfill object
 * 
 */
Floodfill::~Floodfill(){}