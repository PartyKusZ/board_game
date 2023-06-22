#include "File_parser.hpp"
#include "Game_state.hpp"
int main(){
    Game_state state;
    try{
        state = File_parser::get_game_state("maps_and_status/map_1.txt","maps_and_status/state.txt");
        
    }
    catch (const std::runtime_error& re) {
        
        std::cerr << "File_parser::read_map_file(): " << re.what() << '\n';
        return EXIT_FAILURE; // Zwracamy kod błędu
    }

    catch (const std::invalid_argument& ia){
        std::cerr << "File_parser::read_map_file(): Invalid argument: " << ia.what() << '\n';
        return EXIT_FAILURE; // Zwracamy kod błędu

    }

    catch (const std::out_of_range& oor) {
        std::cerr << "Out of range: " << oor.what() << '\n';
        return EXIT_FAILURE; // Zwracamy kod błędu

    }


    
    return 0;

}
