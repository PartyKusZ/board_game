#pragma once 

/**
 * @brief Abstract class representing an unit that may appear on a map
 * 
 */

class Unit{
    protected:
        int stamina;       //!< Stamina of unit
        int speed;         //!< Speed of of unit
        int cost;          //!< Cost of unit
        int attack_range;  //!< Attack range of unit
        int building_time; //!< Building time of unit
    public:
    /*Method descriptions can be found in the corresponding source file */
       
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

        /**
         * @brief The virtaula method for determining the movement of a unit 
         * 
         */
        virtual void move() = 0;

        /**
         * @brief The virtaula method for determining an unit's attack 
         * 
         */
        virtual void attack() = 0;

        ~Unit();
};