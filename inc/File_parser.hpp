#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> 
#include "Map_table.hpp"
#include "Game_state.hpp"

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
    public:
    /*Method descriptions can be found in the corresponding source file */

        File_parser();
        static Game_state get_game_state();
        ~File_parser();
};