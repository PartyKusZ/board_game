#include "File_parser.hpp"


Game_state File_parser::game_state;
/**
 * @brief Construct a new File_parser::File_parser object
 * 
 */
File_parser::File_parser(){};

/**
 * @brief method that splits the string into substrings by space 
 * 
 * @param text string to be split 
 * @return std::vector<std::string> substrings vector
 */
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


bool File_parser::is_a_number(const std::string &string){
    for(char const &c : string) {
        if(!std::isdigit(c))
            return false;
    }
    return true;
}



/**
 * @brief Reads a map from a file and transforms it into a Map_table structure and writes from the game_state object containing the map.
 *
 * This function opens a file, given its name as an argument, then reads line by line, 
 * converting each character into a corresponding field on the map (FREE, OBSTACLE, MY_BASE, 
 * ENEMIE_BASE, MINE).
 *
 * @param filename Name of the file containing the map to be read.
 */

void File_parser::read_map_file(const char *filename){

    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Błąd otwarcia pliku!"); // cannot open file  :(
    }

    std::string line;
    Map_table map_table;
    std::string character;
    for(int i = 0; std::getline(file, line); ++i){
        if(line != ""){ // protection against reading a empty line 

            map_table.push_back({}); // creating a new row of map 

            for(int j = 0; j < line.size(); ++j){ // loop moving through the columns, it means through each char
            
                switch (std::stoi(std::string(1, line[j]))){ // converting char to number 

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
                    map_table[i].push_back({Map_field::MINE,{}});
                    break;
                default:
                    break;
                
            }   
          }
        }else{
            --i;    //reducing the index by an empty line
        }
    }
    game_state.map = map_table; // writnig map to game_state object
}

/**
 * @brief Parses a line from a status file and updates the game state.
 *
 * @param split_line A vector of strings containing the split line from the status file.
 */

void File_parser::parse_status(std::vector<std::string> split_line){
    int id;
    int x_coord;
    int y_coord;
    int stamina;

    Ownership ownership;
    if(split_line.size() > 1 && split_line[0] != ""){ // protection against reading a empty line 
        if(split_line[0] == "P"){
        ownership = Ownership::MINE;
        }else if(split_line[0] == "E"){
            ownership = Ownership::ENEMIES; 
        }
        id      = std::stoi(split_line[2]); // id of current unit 
        x_coord = std::stoi(split_line[3]); // x coord of currnet unit 
        y_coord = std::stoi(split_line[4]); // y coord of current unit
        stamina = std::stoi(split_line[5]); // stamina of current unit

        // this block of code checks what types of units are on the field and creates their objects on the map

        if      (split_line[1] == "K"){
            game_state.map[y_coord][x_coord].units.push_back(new Knight(stamina,id,ownership));
        }else if(split_line[1] == "S"){
            game_state.map[y_coord][x_coord].units.push_back(new Swordsman(stamina,id,ownership));
        }else if(split_line[1] == "A"){
            game_state.map[y_coord][x_coord].units.push_back(new Archer(stamina,id,ownership));
        }else if(split_line[1] == "P"){
            game_state.map[y_coord][x_coord].units.push_back(new Pikeman(stamina,id,ownership));
        }else if(split_line[1] == "C"){
            game_state.map[y_coord][x_coord].units.push_back(new Catapult(stamina,id,ownership));   
        }else if(split_line[1] == "R"){
            game_state.map[y_coord][x_coord].units.push_back(new Ram(stamina,id,ownership));
        }else if(split_line[1] == "W"){
            game_state.map[y_coord][x_coord].units.push_back(new Worker(stamina,id,ownership));

        // When creating a base, check if the base is in 
        // the process of prduction of a unit and if so, create a base with such a unit.

        }else if(split_line[1] == "B"){
            if(is_a_number(split_line[6])){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership));

            }else if(split_line[6] == "K"){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership,Type_of_unit::KNIGHT));
            }else if(split_line[6] == "S"){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership,Type_of_unit::SWORDSMAN));
            }else if(split_line[6] == "A"){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership,Type_of_unit::ARCHER));
            }else if(split_line[6] == "P"){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership,Type_of_unit::PIKEMAN));
            }else if(split_line[6] == "C"){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership,Type_of_unit::CATAPULT));
            }else if(split_line[6] == "R"){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership,Type_of_unit::RAM));
            }else if(split_line[6] == "W"){
                game_state.map[y_coord][x_coord].units.push_back(new Base(stamina,id,ownership,Type_of_unit::WORKER));
            }
        }
    }
    
}

/**
 * @brief Reads a status file to update the game state.
 *
 * @param filename Name of the status file.
 * @throws std::runtime_error If the file cannot be opened.
 */

void File_parser::read_status_file(const char *filename){
    
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Błąd otwarcia pliku!"); // cannot open file :(
    }

    std::string line;
    std::vector<std::string> split_line;
    std::getline(file, line); // read line with gold amount
    game_state.gold_amount = std::stoi(line); // write gold amount to game_state object
    while(std::getline(file, line)){
        split_line = split_by_space(line);
        parse_status(split_line);
    }


}

/**
 * @brief The method calls the methods responsible for the 
 * interpertation of the map and status files, then returns a game state 
 * object representing the game state (amount of gold and map) 
 * 
 * @param map_filename 
 * @param status_filename 
 * @return Game_state 
 */

Game_state File_parser::get_game_state(const char *map_filename,const char *status_filename){
    read_map_file(map_filename);
    read_status_file(status_filename);
    return game_state;
}

void File_parser::save_orders(const char *filename,std::vector<std::string> orders){

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Błąd otwarcia pliku!"); // cannot open file  :(
    }
    for(auto order: orders){
        file << order;
    }
}

/**
 * @brief Destroy the File_parser::File_parser object
 * 
 */
File_parser::~File_parser(){};
