#pragma once 

class Unit{
    protected:
        int stamina;
        int speed;
        int cost;
        int attack_range;
        int building_time;

        virtual void move() = 0;
        virtual void attack() = 0;
        
};