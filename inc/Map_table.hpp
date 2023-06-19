#pragma once 
#include <utility>
#include <vector>
#include "Knight.hpp"
#include "Swordsman.hpp"
#include "Archer.hpp"
#include "Pikeman.hpp"
#include "Ram.hpp"
#include "Catapult.hpp"
#include "Worker.hpp"
#include "Base.hpp"
#include "Map_field.hpp"



using Map_table = std::vector<std::vector<std::pair<Map_field, std::vector<Unit*>>>>;
