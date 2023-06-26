#include "gtest/gtest.h"
#include "../inc/Floodfill.hpp"
#include "../inc/File_parser.hpp"
#include "../inc/Game_state.hpp"

TEST(floodfil_test, corretct_path) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    Floodfill floodfill(state.map);
    floodfill.floodfill({0,0},{0,4});
    std::vector<Coordinartes> path = {{0,0},{0,1},{1,2},{2,3},{1,4}};
    auto fl = floodfill.get_path({0,0},{0,4});
    EXPECT_EQ(floodfill.get_path({0,0},{0,4}),path);
}

TEST(floodfil_test, zero_path) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    Floodfill floodfill(state.map);
    floodfill.floodfill({0,0},{4,4});
    //auto path = floodfill.get_path({0,0},{0,0});
    std::vector<Coordinartes> path;
    EXPECT_EQ(floodfill.get_path({0,0},{0,0}),path);
}

TEST(floodfil_test, zero_path_zero_floodfill) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    Floodfill floodfill(state.map);
    floodfill.floodfill({0,0},{0,0});
    //auto path = floodfill.get_path({0,0},{0,0});
    std::vector<Coordinartes> path;
    EXPECT_EQ(floodfill.get_path({0,0},{0,0}),path);
}