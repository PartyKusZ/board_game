#pragma once
#include <vector>
#include "Map_table.hpp"
class Game_state{
    public:
        long gold_amount;
        Map_table map;
        Game_state();
        void find_my_base();
        void find_enemies_base();
        /*zastanowic sie jakie metody przeszukiwania mapy należy zaimplementować*/
        ~Game_state();
};