#include "gtest/gtest.h"
#include "../inc/File_parser.hpp"
#include "../inc/Enemie_forces_analysis.hpp"
#include "../inc/Enemie_forces.hpp"


TEST(enemie_forces_analysis_test, base_stamina_diff) {
    Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
    auto diff = enemie_forces_analysis.base_stamina_diff(2);

    EXPECT_EQ(diff, std::vector<int>({0}));
}

TEST(enemie_forces_analysis_test, number_of_units_relatively_diff) {
    Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
    auto diff = enemie_forces_analysis.number_of_units_relatively_diff(2);

    EXPECT_EQ(diff, std::vector<int>({0}));
}

TEST(enemie_forces_analysis_test, avr_stamina_diff) {
    Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
    auto diff = enemie_forces_analysis.avr_stamina_diff(2);

    EXPECT_EQ(diff, std::vector<int>({0}));
}

TEST(enemie_forces_analysis_test, avr_speed_diff) {
    Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
    auto diff = enemie_forces_analysis.avr_speed_diff(2);

    EXPECT_EQ(diff, std::vector<int>({0}));
}

TEST(enemie_forces_analysis_test, avr_attack_range_diff) {
    Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
    auto diff = enemie_forces_analysis.avr_attack_range_diff(2);

    EXPECT_EQ(diff, std::vector<int>({0}));
}

// TEST(enemie_forces_analysis_test, base_stamina_diff_invalid_arg) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     auto diff = enemie_forces_analysis.base_stamina_diff(3);

//     EXPECT_EQ(diff, std::vector<int>({0}));
// } works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, base_stamina_diff_invalid_arg_0) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     auto diff = enemie_forces_analysis.base_stamina_diff(0);

//     EXPECT_EQ(diff, std::vector<int>({0}));
// } works  ok -> trows exception and exit with code 1


// TEST(enemie_forces_analysis_test, number_of_units_relatively_diff_invalid_arg) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.number_of_units_relatively_diff(3), std::invalid_argument);
// } works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, number_of_units_relatively_diff_invalid_arg_0) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.number_of_units_relatively_diff(0), std::invalid_argument);
// }works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, avr_stamina_diff_invalid_arg) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.avr_stamina_diff(3), std::invalid_argument);
// }works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, avr_stamina_diff_invalid_arg_0) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.avr_stamina_diff(0), std::invalid_argument);
// }works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, avr_speed_diff_invalid_arg) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.avr_speed_diff(3), std::invalid_argument);
// }works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, avr_speed_diff_invalid_arg_0) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.avr_speed_diff(0), std::invalid_argument);
// }works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, avr_attack_range_diff_invalid_arg) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.avr_attack_range_diff(3), std::invalid_argument);
// }works  ok -> trows exception and exit with code 1

// TEST(enemie_forces_analysis_test, avr_attack_range_diff_invalid_arg_0) {
//     Enemie_forces_analysis enemie_forces_analysis(File_parser::get_enemie_forces());
//     EXPECT_THROW(enemie_forces_analysis.avr_attack_range_diff(0), std::invalid_argument);
// }works  ok -> trows exception and exit with code 1
