#include "Enemie_forces_analysis.hpp"
/**
 * @brief Construct a new Enemie_forces_analysis::Enemie_forces_analysis object
 * 
 * @param _enemie_forces 
 */
Enemie_forces_analysis::Enemie_forces_analysis(std::vector<Enemie_forces> _enemie_forces): enemie_forces(_enemie_forces){}

/**
 *  @brief Calculates the base stamina difference over a certain number of latest turns.
 *  
 *  This function calculates the difference in base stamina of enemy forces between each successive turn.
 *  It uses the last 'latest_turns_numbers' turns.
 *  
 *  @param latest_turns_numbers Number of latest turns to consider.
 *  @return A vector of differences in base stamina.
 *  
 *  @exception std::invalid_argument Thrown if 'latest_turns_numbers' is larger than the size of 'enemie_forces'
 *  or less than 2.
 */

std::vector<int> Enemie_forces_analysis::base_stamina_diff(int latest_turns_numbers){

    try{
        if(latest_turns_numbers > enemie_forces.size()){
            throw std::invalid_argument("latest_turns_numbers jest większe od  enemie_forces");
        }else if(latest_turns_numbers <=  1){
            throw std::invalid_argument("latest_turns_numbers jest mniejsze od 2");
        }

        std::vector<int> base_stamina_diff;
        for(int i = enemie_forces.size() - latest_turns_numbers; i < enemie_forces.size() - 1; i++){
            base_stamina_diff.push_back(enemie_forces[i + 1].base_stamina - enemie_forces[i].base_stamina);
        }

    }
    catch(const std::invalid_argument& e){
        std::cerr << "Enemie_forces_analysis::base_stamina_diff" << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

/**
 *  @brief Calculates the relative difference in the number of units over a certain number of latest turns.
 *  
 *  This function calculates the difference in number of enemy units between each successive turn.
 *  It uses the last 'latest_turns_numbers' turns.
 *  
 *  @param latest_turns_numbers Number of latest turns to consider.
 *  @return A vector of differences in number of units.
 *  
 *  @exception std::invalid_argument Thrown if 'latest_turns_numbers' is larger than the size of 'enemie_forces'
 *  or less than 2.
 */

std::vector<int> Enemie_forces_analysis::number_of_units_relatively_diff(int latest_turns_numbers){
    try{
        if(latest_turns_numbers > enemie_forces.size()){
            throw std::invalid_argument("latest_turns_numbers jest większe od  enemie_forces");
        }else if(latest_turns_numbers <=  1){
            throw std::invalid_argument("latest_turns_numbers jest mniejsze od 2");
        }

        std::vector<int> number_of_units_relatively_diff;
        for(int i = enemie_forces.size() - latest_turns_numbers; i < enemie_forces.size() - 1; i++){
            number_of_units_relatively_diff.push_back(enemie_forces[i + 1].number_of_units_relatively - enemie_forces[i].number_of_units_relatively);
        }

    }
    catch(const std::invalid_argument& e){
        std::cerr << "Enemie_forces_analysis::number_of_units_relatively_diff" << e.what() << '\n';
        exit(EXIT_FAILURE);
        
    }
}

/**
 *  @brief Calculates the average stamina difference over a certain number of latest turns.
 *  
 *  This function calculates the difference in average stamina of enemy forces between each successive turn.
 *  It uses the last 'latest_turns_numbers' turns.
 *  
 *  @param latest_turns_numbers Number of latest turns to consider.
 *  @return A vector of differences in average stamina.
 *  
 *  @exception std::invalid_argument Thrown if 'latest_turns_numbers' is larger than the size of 'enemie_forces'
 *  or less than 2.
 */

std::vector<int> Enemie_forces_analysis::avr_stamina_diff(int latest_turns_numbers){
    try{
        if(latest_turns_numbers > enemie_forces.size()){
            throw std::invalid_argument("latest_turns_numbers jest większe od  enemie_forces");
        }else if(latest_turns_numbers <=  1){
            throw std::invalid_argument("latest_turns_numbers jest mniejsze od 2");
        }

        std::vector<int> avr_stamina_diff;
        for(int i = enemie_forces.size() - latest_turns_numbers; i < enemie_forces.size() - 1; i++){
            avr_stamina_diff.push_back(enemie_forces[i + 1].avr_stamina - enemie_forces[i].avr_stamina);
        }

    }
    catch(const std::invalid_argument& e){
        std::cerr << "Enemie_forces_analysis::avr_stamina_diff" << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

/**
 *  @brief Calculates the average speed difference over a certain number of latest turns.
 *  
 *  This function calculates the difference in average speed of enemy forces between each successive turn.
 *  It uses the last 'latest_turns_numbers' turns.
 *  
 *  @param latest_turns_numbers Number of latest turns to consider.
 *  @return A vector of differences in average speed.
 *  
 *  @exception std::invalid_argument Thrown if 'latest_turns_numbers' is larger than the size of 'enemie_forces'
 *  or less than 2.
 */

std::vector<int> Enemie_forces_analysis::avr_speed_diff(int latest_turns_numbers){
    try{
        if(latest_turns_numbers > enemie_forces.size()){
            throw std::invalid_argument("latest_turns_numbers jest większe od  enemie_forces");
        }else if(latest_turns_numbers <=  1){
            throw std::invalid_argument("latest_turns_numbers jest mniejsze od 2");
        }

        std::vector<int> avr_speed_diff;
        for(int i = enemie_forces.size() - latest_turns_numbers; i < enemie_forces.size() - 1; i++){
            avr_speed_diff.push_back(enemie_forces[i + 1].avr_speed - enemie_forces[i].avr_speed);
        }

    }
    catch(const std::invalid_argument& e){
        std::cerr << "Enemie_forces_analysis::avr_speed_diff" << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

/**
 *  @brief Calculates the average attack range difference over a certain number of latest turns.
 *  
 *  This function calculates the difference in average attack range of enemy forces between each successive turn.
 *  It uses the last 'latest_turns_numbers' turns.
 *  
 *  @param latest_turns_numbers Number of latest turns to consider.
 *  @return A vector of differences in average attack range.
 *  
 *  @exception std::invalid_argument Thrown if 'latest_turns_numbers' is larger than the size of 'enemie_forces'
 *  or less than 2.
 */

std::vector<int> Enemie_forces_analysis::avr_attack_diff(int latest_turns_numbers){
    try{
        if(latest_turns_numbers > enemie_forces.size()){
            throw std::invalid_argument("latest_turns_numbers jest większe od  enemie_forces");
        }else if(latest_turns_numbers <=  1){
            throw std::invalid_argument("latest_turns_numbers jest mniejsze od 2");
        }

        std::vector<int> avr_attack_diff;
        for(int i = enemie_forces.size() - latest_turns_numbers; i < enemie_forces.size() - 1; i++){
            avr_attack_diff.push_back(enemie_forces[i + 1].avr_attack_range - enemie_forces[i].avr_attack_range);
        }

    }
    catch(const std::invalid_argument& e){
        std::cerr << "Enemie_forces_analysis::avr_attack_diff" << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}
/**
 * @brief Destroy the Enemie_forces_analysis::Enemie_forces_analysis object
 * 
 */
Enemie_forces_analysis::~Enemie_forces_analysis(){}