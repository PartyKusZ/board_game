#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> 
#include "Map_table.hpp"
#include "Game_state.hpp"
#include "Enemie_forces.hpp"

/**
 * @brief Class for reading and parsing MAPA.txt and STATUS.txt
 * 
 */

class File_parser{
    private:
        static constexpr int FREE = 0; //!< free field
        static constexpr int OBSTACLE = 9; //!< obsolete field
        static constexpr int MY_BASE = 1; //!< my base field
        static constexpr int ENEMIE_BASE = 2; //!< enemie base field
        static constexpr int MINE = 6;  //!< mine field
        static Game_state game_state; //!< representing map

        static void  read_map_file(const char *filename);
        static void read_status_file(const char *filename);
        static std::vector<std::string> split_by_space(const std::string &string);
        static bool is_a_number(const std::string &string);
        static void parse_status(std::vector<std::string> split_line);
    public:
    /*Method descriptions can be found in the corresponding source file */

        File_parser();
        static Game_state get_game_state(const char *map_filename,const char *status_filename);
        static void save_orders(const char *filename, std::vector<std::string> orders);
        static void save_enemie_forces(const Enemie_forces &enemie_forces);
        static std::vector<Enemie_forces> get_enemie_forces();
        ~File_parser();
};