#include "gtest/gtest.h"
#include "../inc/Floodfill.hpp"
#include "../inc/File_parser.hpp"
#include "../inc/Game_state.hpp"

TEST(file_parser_test, my_base_free) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");

    EXPECT_EQ(state.map[0][0].map_filed,Map_field::FREE);
}

TEST(file_parser_test, gold_amuount) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");

    EXPECT_EQ(state.gold_amount,2500);
}

TEST(file_parser_test, eneme_base_obscalate) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");

    EXPECT_EQ(state.map[4][4].map_filed,Map_field::OBSTACLE);

}