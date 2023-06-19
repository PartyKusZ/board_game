#pragma once 
#include "Type_of_unit.hpp"
#include "Ownership.hpp"
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

        Type_of_unit type_of_unit; //!< Type of unit
        Ownership ownership; //!< Ownership of unit
    public:
    /*Method descriptions can be found in the corresponding source file */
       
        Unit(int _stamina, int _speed, int _cost, int _attack_range, int _building_time, Type_of_unit _type_of_unit, Ownership _ownership);

        virtual int get_stamina() const;
        virtual int get_speed() const;
        virtual int get_cost() const;
        virtual int  get_attack_range() const;
        virtual int get_building_time() const;
        virtual Type_of_unit get_type_of_unit() const;
        virtual Ownership get_ownership() const;

        virtual void set_stamina(int value);
        virtual void set_speed(int value);
        virtual void set_cost(int value);
        virtual void set_attack_range(int value);
        virtual void set_building_time(int value);

        /**
         * @brief The virtaula method for determining the movement of a unit 
         * 
         */
       // virtual void move() = 0;

        /**
         * @brief The virtaula method for determining an unit's attack 
         * 
         */
       // virtual void attack() = 0;

        virtual ~Unit();
};