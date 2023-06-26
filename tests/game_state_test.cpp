#include "gtest/gtest.h"
#include "../inc/Floodfill.hpp"
#include "../inc/File_parser.hpp"
#include "../inc/Game_state.hpp"

TEST(game_state_test, find_base) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    
    EXPECT_EQ(state.find_base(Ownership::MINE),state.map[0][0].units.front());
}

TEST(game_state_test, find_mines) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    std::vector<Coordinartes> mines ={{4,0},{0,1},{3,4}};
    EXPECT_EQ(state.find_mines(),mines);
}


TEST(game_state_test, amount_of_my_units) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    EXPECT_EQ(state.find_all_units(Ownership::MINE).size(),1);
}


TEST(game_state_test, get_coordinate_by_id) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    auto my = state.find_all_units(Ownership::MINE);
    Coordinartes cord = {0,0};
    EXPECT_EQ(state.get_coordinate_by_id(my.front()),cord);
}

TEST(game_state_test, distance_between_units) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    auto my = state.find_all_units(Ownership::MINE);
    auto enemy = state.find_all_units(Ownership::ENEMIES);

    EXPECT_EQ(state.distance_between_units(my.front(),enemy.front()),3);
}

TEST(game_state_test, distance_between_units_coord_unit) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    auto my = state.find_all_units(Ownership::MINE);
    auto enemy = state.find_all_units(Ownership::ENEMIES);

    EXPECT_EQ(state.distance_between_units(state.get_coordinate_by_id(my.front()),enemy.front()),3);
}

TEST(game_state_test, distance_between_units_coord_coord) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    auto my = state.find_all_units(Ownership::MINE);
    auto enemy = state.find_all_units(Ownership::ENEMIES);

    EXPECT_EQ(state.distance_between_units(state.get_coordinate_by_id(my.front()),state.get_coordinate_by_id(enemy.front())),3);
}

TEST(game_state_test, is_enemy_within_attack_range) {
    auto state = File_parser::get_game_state("mapa.txt","status.txt");
    auto my = state.find_all_units(Ownership::MINE);
    auto enemy = state.find_all_units(Ownership::ENEMIES);

    EXPECT_EQ(state.is_enemy_within_attack_range(my.front(),enemy.front()),true);
}
