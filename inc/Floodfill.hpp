#pragma once    
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include "Map_table.hpp"
#include "Coordinates.hpp"
/**
 * @brief Class representing the floodfill algorithm for optimal pathfinding on a map
 * 
 * @details The Flood Fill algorithm works by marking each accessible field on the game 
 * map according to its distance from the target. The algorithm starts from the target, 
 * then "floods" out to neighboring fields, incrementing the distance with each step. This 
 * process continues until it reaches the unit or fills the entire map. After all fields have 
 * been marked, the unit can move towards the target always moving to the field with the smallest 
 * value, resulting in the shortest possible path.
 * 
 */

class Floodfill_filed{
    public:
    int floodfill_value = INT_MAX;
    Map_field field;
};

class Floodfill{
    /*Method descriptions can be found in the corresponding source file */

    private: 
        int map_width; //!< map width 
        int map_height; //!< map_height
        const Map_table map_with_units; //!< a map with full information on the state of the game (deployment of units, etc.).
        std::vector<std::vector<Floodfill_filed>> map;  //!<  a map showing only which field is accessible to the player's program
        std::vector<Coordinartes> get_neighbouring_fields(Coordinartes xy);
        bool is_target_neighbour(Coordinartes current, Coordinartes target);
        Coordinartes neighbour_with_the_smallest_value(Coordinartes xy);
    public:

        Floodfill(const Map_table _map);
        void floodfill(const Coordinartes &from, const Coordinartes &to); 
        std::vector<Coordinartes> get_path(const Coordinartes &from, const Coordinartes &to);
        ~Floodfill();
};