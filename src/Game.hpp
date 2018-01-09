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

// for gtest
#define GTEST
#ifdef GTEST
#include "gtest/gtest_prod.h"
#endif

namespace klondike{

class Game {
private:
    std::vector<Stack> stacks;
    Deck discard;
    Deck deck;
    std::map<Card::RankValue, Foundation> foundations;

    void print_stacks() const;
    void print_deque() const;

    FRIEND_TEST(GameTest, move);
    FRIEND_TEST(GameTest, move_to_pile);
public:
    Game();
    ~Game();
    void print() const;
    void move(int from_stack, int n, int to_stack);
    void move(int from_stack);
    //void move_to_pile();

protected:

};

}
#endif /* Game_hpp */
