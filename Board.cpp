#include "City.hpp"
#include <iostream>
#include "Board.hpp"
namespace pandemic {
    // const int Board::operator[](City c) const{
    // return 0;
    // }
    int& Board::operator[](City city){
        
        return Board::x;
    }
    //int get(uint index) {return theInts[index];} // Java style
    //void set(uint index, int newValue); // Java style
     std::ostream& operator << (std::ostream& output, const Board& board){
        return output;
    }
    bool Board::is_clean(){
        return true;
    }
    void Board::remove_cures(){}
    void Board::remove_stations(){}
    

};
