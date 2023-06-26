#include <cstring>
#include "File_parser.hpp"
#include "Game_state.hpp"
#include "Floodfill.hpp"
#include "Commander.hpp"

/*unit tests*/
void game_state_tests(Game_state state){
    /*użyto plików state.txt i map_1.txt*/
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
    
/*ok */
}

void floodfill_tests(Map_table map){
    /*użyto plików mapa.txt  i state_only_gold.txt*/
    Floodfill floodfill(map);
    floodfill.floodfill({0,0},{31,4});
    auto path = floodfill.get_path({0,0},{31,4});
    return; /*ok*/

}

int main(int argc, char** argv){
    if(strcmp(argv[1], "mapa.txt") != 0 || strcmp(argv[2], "status.txt") != 0 || strcmp(argv[3], "rozkazy.txt") != 0){
        std::cout << argv[1] << argv[2] << argv[3] << std::endl;
        std::cerr << "Wrong arguments!\nexpect mapa.txt status.txt rozkazy.txt [t]" << std::endl;
        return EXIT_FAILURE;
    } 
    Game_state state = File_parser::get_game_state("mapa.txt","status.txt");
    Commander commander(state);
    commander.give_orders("rozkazy.txt");
    
    return 0;

}
