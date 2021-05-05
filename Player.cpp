#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic {
        Player::Player(Board board,City city){
            
        }
        Player& Player::drive(City city){
            return *this;
        };
        Player& Player::fly_direct(City city){
        return *this;

        };
        Player& Player::fly_charter (City city){
        return *this;

        };
        Player& Player::fly_shuttle(City city){
        return *this;
        };
        void Player::build(){};
        Player& Player::discover_cure (Color color){
                        return *this;

        }
        Player& Player::treat (City city){            return *this;
        };
        std::string Player::role (){            
            return "";
        };
        Player& Player::take_card (City city){            
            return *this;
        };
        void remove_cards(){};





    };
