#include "File_parser.hpp"



/**
 * @brief Construct a new File_parser::File_parser object
 * 
 */
File_parser::File_parser(){};

Map_table File_parser::read_map_file(const char *filename){

    std::ifstream file(filename); // napisać obsługę wyjątku 
    std::string line;
    Map_table map_table;
    while(std::getline(file, line)){
        map_table.push_back({});
        for(int i = 0; i < line.size(); i++){
            switch (std::stoi(&line[i])){

            case FREE:
                map_table[i].push_back({Map_field::FREE,{}});
                break;

            case OBSTACLE:
                map_table[i].push_back({Map_field::OBSTACLE,{}});
                break;

            case MY_BASE:
                map_table[i].push_back({Map_field::FREE,{new Base(Ownership::MINE)}});
                break;

            case ENEMIE_BASE:
                map_table[i].push_back({Map_field::OBSTACLE,{new Base(Ownership::ENEMIES)}});
                break;
                
            case MINE:
                map_table[i].push_back({Map_field::OBSTACLE,{}});
                break;
            default:
                break;
            }
        }
    }
    return map_table;    
}
/**
 * @brief Destroy the File_parser::File_parser object
 * 
 */
File_parser::~File_parser(){};
