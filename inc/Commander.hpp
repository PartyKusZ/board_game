#pragma once 

#include <map>
#include <algorithm>
#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept> 
#include "Floodfill.hpp"
#include "Game_state.hpp"
#include "File_parser.hpp"
#include "Enemie_forces_analysis.hpp"

/**
 * @class Commander
 * @brief The Commander class manages game units and their actions.
 *
 * The Commander class is responsible for managing the state of the game, issuing orders, 
 * managing combat operations, and synchronizing multithreaded operations. It contains information about the 
 * current state of the game, bases and units for both the player and the enemy, as well as data structures
 * for issuing and executing orders.
 *
 * The class provides functions to handle game state analysis and units' management such as moving, attacking, 
 * creating units and more. It also provides utility methods for calculating game statistics, such as average 
 * unit speed, stamina, attack range, etc.
 *
 * Threading is used to enable concurrent operations, managed through the use of a mutex and a vector of active threads.
 *
 * A variety of game strategies could be implemented by modifying the logic within this class.
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

        Enemie_forces_analysis enemie_forces_analysis; //!< Object responsible for analyzing the enemy's forces.


        int base_with_more_stamina();
        int average_unit_stamina(std::vector<Unit *> units);
        int average_unit_speed(std::vector<Unit *> units);
        int average_unit_attack_range(std::vector<Unit *> units);
        int percent_of_units_around_base(Base *base, std::vector<Unit *> units, int range);
        int percent_of_units_around_mine(Coordinartes mine, std::vector<Unit *> units, int range);
        int damage_inflicited(Type_of_unit attacker, Type_of_unit attacked);
        double number_of_units_relatively(std::vector<Unit *> units);
        std::vector<Unit *> are_units_in_attack_range(Unit *my_unit, std::vector<Unit *> enemies_unit);
        Ownership who_will_win_skirmish(Unit *my_unit, Unit *enemy_unit);
        std::vector<Type_of_unit> what_can_i_build();
        void move_unit(Unit *unit, Coordinartes xy, int speed);
        void attack_unit(Unit *unit_1, Unit *unit_2);
        void create_unit(Type_of_unit unit);

        void initial_game_phase();






    public:
        Commander(Game_state _state);
        void give_orders(const char *filename);
        ~Commander();
};