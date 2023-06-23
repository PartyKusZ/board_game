#pragma once    
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include "Map_table.hpp"
#include "Coordinates.hpp"
/**
 * @brief 
 * 
 */

class Floodfill_filed{
    public:
    int floodfill_value = INT_MAX;
    Map_field field;
};

class Floodfill{
    private: 
        int map_width;
        int map_height;
        const Map_table map_with_units;
        std::vector<std::vector<Floodfill_filed>> map;  
        std::vector<Coordinartes> get_neighbouring_fields(Coordinartes xy);
        bool is_target_neighbour(Coordinartes current, Coordinartes target);
        Coordinartes neighbour_with_the_smallest_value(Coordinartes xy);
    public:
    /*Method descriptions can be found in the corresponding source file */

        Floodfill(const Map_table _map);
        void floodfill(const Coordinartes &from, const Coordinartes &to); 
        std::vector<Coordinartes> get_path(const Coordinartes &from, const Coordinartes &to);
        ~Floodfill();
};