#pragma once 
/**
 * @brief Simple class storing x y coordinates
 * 
 */
class Coordinartes{
    public:
        int x; //!< x coordinate
        int y; //!< y coordinate
        bool operator==(const  Coordinartes& other) const { return x == other.x && y == other.y; }
};