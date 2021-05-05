#pragma once
#include "City.hpp"
#include <iostream>
namespace pandemic {
    class Board{
    int x;

    public:
    //const int operator[](City c) const;
    int& operator[](City c);
    //int get(uint index) {return theInts[index];} // Java style
    //void set(uint index, int newValue); // Java style
    friend std::ostream& operator << (std::ostream& output, const Board& board);
    static bool is_clean();
    void remove_cures();
    void remove_stations();
    

    };
};
