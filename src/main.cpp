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

    Coordinartes xy;
    auto base = state.find_base(Ownership::MINE);
    auto enem_base = state.find_base(Ownership::ENEMIES);
    xy = state.get_coordinate_by_id(base);
    std::cout << "x: " << xy.x << std::endl;
    std::cout << "y: " << xy.y << std::endl;
    std::cout << "======================" << std::endl;

    auto units = state.find_all_units(Ownership::MINE);
    for(auto unit : units){
        xy = state.get_coordinate_by_id(unit);
        std::cout << "id: " << unit->get_id() << std::endl;
        std::cout << "x: " << xy.x << std::endl;
        std::cout << "y: " << xy.y << std::endl;
        std::cout << "------" << std::endl;

    }
    std::cout << "======================" << std::endl;
    std::cout << "distance beetwenn units: " <<  state.distance_between_units(base,enem_base) << std::endl;

    std::cout << "======================" << std::endl;
    auto enem_units = state.find_all_units(Ownership::ENEMIES);

    for(auto unit: units){
        for(auto enem_unit: enem_units){
            if(state.is_enemy_within_attack_range(unit,enem_unit)){
                std::cout << "unit id: " << unit->get_id() << std::endl;
                std::cout << "enem_unit id: " << enem_unit->get_id() << std::endl;
                std::cout << "enemies unit in attack range!" << std::endl;
            }
        }
    }

    std::cout << "======================" << std::endl;

    auto mines = state.find_mines();
    for(auto mine: mines){
        std::cout << "x: " << mine.x << std::endl;
        std::cout << "y: " << mine.y << std::endl;
        std::cout << "------" << std::endl;
    }
    



    
    return 0;

}
