#pragma once 

/**
 * @class Enemie_forces
 * @brief This class represents the average properties of enemy forces in a game.
 *
 * The class stores the turn number and the average statistics for enemy forces, including stamina, speed, and attack range.
 * These properties can be used to calculate the battle strategies, performance metrics, or AI behavior in the game.
 */

class Enemie_forces{   
    public:
        int turn_number;
        int base_stamina;
        int number_of_units_relatively;
        int avr_stamina;
        int avr_speed;
        int avr_attack_range;
        /*for test compiling*/
        bool operator==(const Enemie_forces &other) const {
            return turn_number == other.turn_number && 
            base_stamina == other.base_stamina && 
            number_of_units_relatively == other.number_of_units_relatively && 
            avr_stamina == other.avr_stamina && avr_speed == other.avr_speed && 
            avr_attack_range == other.avr_attack_range;}
};