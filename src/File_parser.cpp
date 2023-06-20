#include "File_parser.hpp"


Game_state File_parser::game_state;
/**
 * @brief Construct a new File_parser::File_parser object
 * 
 */
File_parser::File_parser(){};


std::vector<std::string> File_parser::split_by_space(const std::string& text) {
    std::vector<std::string> fragments;
    std::string::size_type prev_pos = 0;
    std::string::size_type pos = text.find(' ');

    while (pos != std::string::npos) {
        std::string fragment = text.substr(prev_pos, pos - prev_pos);
        fragments.push_back(fragment);

        prev_pos = pos + 1;
        pos = text.find(' ', prev_pos);
    }

    std::string last_fragment = text.substr(prev_pos);
    fragments.push_back(last_fragment);

    return fragments;
}



/**
 * @brief Reads a map from a file and transforms it into a Map_table structure.
 *
 * This function opens a file, given its name as an argument, then reads line by line, 
 * converting each character into a corresponding field on the map (FREE, OBSTACLE, MY_BASE, 
 * ENEMIE_BASE, MINE).
 *
 * @param filename Name of the file containing the map to be read.
 * @return Map_table structure representing the map read from the file.
 */

void File_parser::read_map_file(const char *filename){

    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Błąd otwarcia pliku!"); // nie udało się otworzyć pliku :(
    }

    std::string line;
    Map_table map_table;
    std::string character;
    for(int i = 0; std::getline(file, line); ++i){

        map_table.push_back({}); // tworzenie nowego wiersza mapy

        for(int j = 0; j < line.size(); ++j){ // uzupełniane wiersza 
        
            switch (std::stoi(std::string(1, line[j]))){ // rzuca wyjątek jeśli character jest niprawidłowy 

            case FREE:
                map_table[i].push_back({Map_field::FREE,{}});
                break;

            case OBSTACLE:
                map_table[i].push_back({Map_field::OBSTACLE,{}});
                break;

            case MY_BASE:
                map_table[i].push_back({Map_field::FREE,{}});
                break;

            case ENEMIE_BASE:
                map_table[i].push_back({Map_field::OBSTACLE,{}});
                break;
                
            case MINE:
                map_table[i].push_back({Map_field::FREE,{}});
                break;
            default:
                break;
            }
        }
    }
    game_state.map = map_table;
}


void File_parser::parse_status(std::vector<std::string> split_line){
    Ownership ownership;

    if(split_line[0] == "P"){
        ownership = Ownership::MINE;
    }else if(split_line[0] == "E"){
        ownership = Ownership::ENEMIES; 
    }
    
}

void File_parser::read_status_file(const char *filename){
    
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Błąd otwarcia pliku!"); // nie udało się otworzyć pliku :(
    }

    std::string line;
    std::vector<std::string> split_line;
    std::getline(file, line);
    game_state.gold_amount = std::stoi(line);
    while(std::getline(file, line)){
        split_line = split_by_space(line);
        


    }


}


Game_state File_parser::get_game_state(){
    return game_state;
}


/**
 * @brief Destroy the File_parser::File_parser object
 * 
 */
File_parser::~File_parser(){};
