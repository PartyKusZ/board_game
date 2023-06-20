#include "File_parser.hpp"
#include "Map_table.hpp"
int main(){

    Map_table map = File_parser::read_map_file("mapa.txt");
    map[0][1].second.push_back(new Ram(Ownership::MINE));
    return 0;

}