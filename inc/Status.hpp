#pragma once
#include <vector>
#include "Unit.hpp"
class Status{
    public:
        long gold_amount;
        std::vector<Unit*> units;
};