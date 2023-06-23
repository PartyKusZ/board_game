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
            }else if(map_with_units[i][j].map_filed == Map_field::FREE){
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


void Floodfill::floodfill(const Coordinartes &from, const Coordinartes &to){
    int curent_val = 0;
    std::queue<Coordinartes> queue;
    Coordinartes current_coord;

    queue.push(from);
    while(!queue.empty()){
        current_coord = queue.front(); 
        queue.pop();
        map[current_coord.y][current_coord.x].floodfill_value = curent_val++;
        if(is_target_neighbour(current_coord, to)) {
            break;
        }
        auto neighbours = get_neighbouring_fields(current_coord);
        for(int i = 0; i < neighbours.size(); ++i){
            map[neighbours[i].y][neighbours[i].x].floodfill_value = curent_val;
            queue.push(neighbours[i]);
        }
    }
} 


Floodfill::~Floodfill(){}