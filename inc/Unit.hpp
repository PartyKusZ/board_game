#pragma once 

class Unit{
    protected:
        int stamina;
        int speed;
        int cost;
        int attack_range;
        int building_time;
    public:

        Unit(int _stamina, int _speed, int _cost, int _attack_range, int _building_time);

        inline int get_stamina() const;
        inline int get_speed() const;
        inline int get_cost() const;
        inline int get_attack_range() const;
        inline int get_building_time() const;

        inline void set_stamina(int value);
        inline void set_speed(int value);
        inline void set_cost(int value);
        inline void set_attack_range(int value);
        inline void set_building_time(int value);


        virtual void move() = 0;
        virtual void attack() = 0;

        ~Unit();
};