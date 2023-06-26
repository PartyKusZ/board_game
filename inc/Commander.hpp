#pragma once 

#include <map>
#include <iostream>
#include <thread>
#include <mutex>
#include "Floodfill.hpp"
#include "Game_state.hpp"
#include "File_parser.hpp"

/**
 * @brief 
 * 
 */

class Commander{
    /*Method descriptions can be found in the corresponding source file */

    private:
        std::mutex mutex; //!< Mutex for synchronizing threads.
        std::vector<std::thread> threads; //!< Vector storing the currently active threads.
        Game_state game_state; //!< Object representing the current state of the game, such as positions of units on the map and gold quantity.
        std::map<Type_of_unit, std::map<Type_of_unit, int>> attack_table; //!< Map that determines the damage inflicted on unit B by unit A.
        Base *my_base; //!< Pointer to the player's base.
        Base *enemy_base; //!< Pointer to the enemy's base.
        std::vector<Unit *> my_units; //!< Vector storing pointers to the player's units.
        std::vector<Unit *> enemy_units; //!< Vector storing pointers to the enemy's units.
        std::vector<Coordinartes> mines; //!< Vector storing the coordinates of mines.
        std::vector<std::string> orders; //!< Vector storing issued commands or orders.


        int base_with_more_stamina();
        int average_unit_stamina(std::vector<Unit *> units);
        int average_unit_speed(std::vector<Unit *> units);
        int average_unit_attack_range(std::vector<Unit *> units);
        int percent_of_units_around_base(Base *base, std::vector<Unit *> units, int range);
        int percent_of_units_around_mine(Coordinartes mine, std::vector<Unit *> units, int range);
        int damage_inflicited(Type_of_unit attacker, Type_of_unit attacked);
        int number_of_units_relatively(std::vector<Unit *> units);
        std::vector<Unit *> are_units_in_attack_range(Unit *my_unit, std::vector<Unit *> enemies_unit);
        Ownership who_will_win_skirmish(Unit *my_unit, Unit *enemy_unit);

        void move_unit(Unit *unit, Coordinartes xy, int speed);
        void attack_unit(Unit *unit_1, Unit *unit_2);
        void create_unit(Type_of_unit unit);








    public:
        Commander(Game_state _state);
        void give_orders(const char *filename);
        ~Commander();
};