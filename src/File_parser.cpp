#include "File_parser.hpp"



/**
 * @brief Construct a new File_parser::File_parser object
 * 
 */
File_parser::File_parser(){};

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

Map_table File_parser::read_map_file(const char *filename){

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
                map_table[i].push_back({Map_field::FREE,{new Base(Ownership::MINE)}});
                break;

            case ENEMIE_BASE:
                map_table[i].push_back({Map_field::OBSTACLE,{new Base(Ownership::ENEMIES)}});
                break;
                
            case MINE:
                map_table[i].push_back({Map_field::FREE,{}});
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
