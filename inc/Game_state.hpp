#pragma once
#include <vector>
#include <cmath>
#include "Map_table.hpp"
#include "Coordinates.hpp"

/**
 * @brief A class storing the amount of available gold and a map. It also provides a set of methods to get information about the units on the map.
 * 
 */
class Game_state{
    public:
        long gold_amount; //!< amount of gold
        Map_table map; //!< representation of map

    /*Method descriptions can be found in the corresponding source file */

        Game_state();
        Unit *find_base(Ownership ownership);
        std::vector<Coordinartes> find_mines();
        std::vector<Unit *> find_all_units(Ownership ownership);
        int distance_between_units(Unit *unit_1, Unit *unit_2);
        Coordinartes get_coordinate_by_id(Unit *unit);
        bool is_enemy_within_attack_range(Unit *my_unit, Unit *enemy_unit);
        ~Game_state();
};