#pragma once 

#include <map>
#include "Floodfill.hpp"
#include "Game_state.hpp"

/**
 * @brief 
 * 
 */

class Commander{
    /*Method descriptions can be found in the corresponding source file */

    private:
        Game_state game_state; //!< represents the current state of the game; position of units on the map and amount of gold 
        Floodfill floodfill; //!< represents the floodfill algorithm
        std::map<Type_of_unit, std::map<Type_of_unit, int>> attack_table; //!<  determines the damage inflicted on unit B by unit A 
        Base *my_base; //!< my base
        Base *enemy_base; //!< enemy base
        std::vector<Unit *> my_units;
        std::vector<Unit *> enemy_units;
        std::vector<Coordinartes> mines;

        int base_with_more_stamina();
        int average_unit_stamina(std::vector<Unit *> units);
        int average_unit_speed(std::vector<Unit *> units);
        int average_unit_attack_range(std::vector<Unit *> units);
        int percent_of_units_around_base(Base *base, std::vector<Unit *> units, int range);
        int percent_of_units_around_mine(Coordinartes mine, std::vector<Unit *> units, int range);
        int damage_inflicited(Type_of_unit attacker, Type_of_unit attacked);
        std::vector<Unit *> are_units_in_attack_range(Unit *my_unit, std::vector<Unit *> enemies_unit);
        Ownership who_will_win_skirmish(Unit *my_unit, Unit *enemy_unit);





    public:
        Commander(Game_state _state);
        ~Commander();
};