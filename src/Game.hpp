//
//  Game.hpp
//  klondike
//
//  Created by <author> on 06/01/2018.
//
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <map>
#include <iostream>

#include "Deck.hpp"
#include "Card.hpp"
#include "Stack.hpp"
#include "Foundation.hpp"

namespace klondike{

class Game {
private:
    std::vector<Stack> stacks;
    Deck discard;
    Deck deck;
    std::map<Card::RankValue, Foundation> foundations;

    void print_stacks() const;
public:
    Game();
    ~Game();
    void print() const;
    //void move_to_pile();

protected:

};

}
#endif /* Game_hpp */
