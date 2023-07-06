#pragma once 
#include "Enemie_forces.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 *  @class Enemie_forces_analysis
 *  @brief A class used for analysis of enemy forces.
 *
 *  This class takes a vector of 'Enemie_forces' objects and provides methods for various analyses.
 *  The main functionality includes calculation of differences in various attributes (like stamina,
 *  speed, attack, etc.) of the enemy forces over specified numbers of latest turns.
 */

class Enemie_forces_analysis{
    private:
        std::vector<Enemie_forces> enemie_forces;//!< Vector containing all enemy forces
    public:
    /*Method descriptions can be found in the corresponding source file */

        Enemie_forces_analysis(std::vector<Enemie_forces> _enemie_forces);
        std::vector<int> base_stamina_diff(int latest_turns_numbers);
        std::vector<int> number_of_units_relatively_diff(int latest_turns_numbers);
        std::vector<int> avr_stamina_diff(int latest_turns_numbers);
        std::vector<int> avr_speed_diff(int latest_turns_numbers);
        std::vector<int> avr_attack_diff(int latest_turns_numbers);
        ~Enemie_forces_analysis();
};