#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <string>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


using namespace pandemic;
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    OperationsExpert OperationsExpert1 {board, City::Atlanta}; 
    FieldDoctor FieldDoctor1(board, City::Washington);
    Virologist Virologist1(board, City::Bogota );
    Medic Medic1(board, City::Washington);
	Dispatcher Dispatcher1(board, City::Kolkata );
	GeneSplicer GeneSplicer1(board, City::SaoPaulo);
	Researcher Researcher1(board, City::Osaka );
	Scientist Scientist1(board, City::Washington, 4);

    GeneSplicer GeneSplicer2(board, City::Paris );

TEST_CASE("Good code") {
    CHECK(board.is_clean());
	board[City::Kinshasa] = 3;
    board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
    CHECK(!(board.is_clean()));

    Researcher1.take_card(City::NewYork);
    CHECK_NOTHROW(Researcher1.fly_direct(City::NewYork));
    Researcher1.take_card(City::NewYork);
    CHECK_NOTHROW(Researcher1.fly_charter(City::Mumbai ));

    CHECK_NOTHROW(OperationsExpert1.drive(City::Chicago));

    CHECK_EQ(OperationsExpert1.role(),"OperationsExpert");
    CHECK_EQ(FieldDoctor1.role(),"FieldDoctor");
    CHECK_EQ(Virologist1.role(),"Virologist");
    CHECK_EQ(Medic1.role(),"Medic");
    CHECK_EQ(Dispatcher1.role(),"Dispatcher");
    CHECK_EQ(GeneSplicer1.role(),"GeneSplicer");
    CHECK_EQ(Researcher1.role(),"Researcher");
    CHECK_EQ(Scientist1.role(),"Scientist");

    CHECK_EQ(GeneSplicer1.role(),GeneSplicer2.role());



}
TEST_CASE("Bad code") {
    CHECK_THROWS(board[City::Kinshasa] = -3);
    CHECK_THROWS(Medic1.drive(City::Tokyo));
    CHECK_THROWS(Medic1.drive(City::Milan));
    CHECK_FALSE(board.is_clean());
    CHECK_THROWS(Dispatcher1.fly_direct(City::Lagos));
    CHECK_THROWS(Dispatcher1.fly_charter(City::Lagos));
    CHECK_THROWS(Virologist1.drive(City::Bangkok));
    CHECK_THROWS(Virologist1.drive(City::Bangkok));

    CHECK_THROWS(GeneSplicer2.drive(City::Riyadh));

}
