#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Map_table.hpp"

class File_parser{
    private:
        static constexpr int FREE = 0;
        static constexpr int OBSTACLE = 9;
        static constexpr int MY_BASE = 1;
        static constexpr int ENEMIE_BASE = 2;
        static constexpr int MINE = 6;
    public:
        File_parser();
        static Map_table read_map_file(const char *filename);
        ~File_parser();
};