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

/**
 * @brief This complex type describes a map. Let me explain how it is structured; it is a two-dimensional vector that represents all the fields on the map.
 *  A single map field consists of:
 *      1. information about what type of field it is (FREE, OBSTACLE ...).
 *      2. a vector of units within the field 
 * 
 */

using Map_table = std::vector<std::vector<std::pair<Map_field, std::vector<Unit*>>>>;
