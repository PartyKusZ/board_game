#include "gtest/gtest.h"
#include "../inc/Floodfill.hpp"
#include "../inc/File_parser.hpp"
#include "../inc/Game_state.hpp"
#include "../inc/Enemie_forces.hpp"

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

// TEST(file_parser_test, save_enemy_forces) {
//     File_parser::save_enemie_forces({1,2,7,9,2,5});
//     /*output in game.txt -> good output*/
// }

TEST(file_parser_test, get_enemie_forces) {
    std::vector<Enemie_forces> state = File_parser::get_enemie_forces();
    std::vector<Enemie_forces> exprect = {{1,2,7,9,2,5},{1,2,7,9,2,5}};
    EXPECT_EQ(state,exprect);

}

/*returns an exception from standing, it is not possible to convert anything to int */
// TEST(file_parser_test, empty_status_file) {
//     auto state = File_parser::get_game_state("mapa.txt","statuse.txt");

//     EXPECT_EQ(state.map[4][4].map_filed,Map_field::OBSTACLE);

// }