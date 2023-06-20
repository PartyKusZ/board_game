#include "File_parser.hpp"
#include "Map_table.hpp"
int main(){
    Map_table map;
    try{
         map = File_parser::read_map_file("mapa.txt");
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


    map[0][1].units.push_back(new Ram(Ownership::MINE));
    return 0;

}