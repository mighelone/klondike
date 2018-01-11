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

    const unsigned int N_STACKS = 7;

    class Game {
    private:
        std::vector<Stack> stacks;
        Deck discard;
        Deck deck;
        std::map<Card::RankValue, Foundation> foundations;

        void print_stacks() const;
        void print_deque() const;
        void print_foundations() const;

        #ifdef GTEST
        FRIEND_TEST(GameTest, move);
        FRIEND_TEST(GameTest, move_king);
        FRIEND_TEST(GameTest, move_to_foundation);
        FRIEND_TEST(GameTest, move_from_discard);
        FRIEND_TEST(GameTest, move_from_discard_f);
        #endif
    public:
        Game();
        ~Game();
        void print() const;
        // move n cards from_stack to_stack
        void move(int from_stack, int n, int to_stack);
        // move card from stack to its foundation
        void move(int from_stack);
        void move_from_discard(int n);
        void move_from_discard();

        void print_prompt() const;
        void prompt();
        void move_to_discard();
        //void move_to_pile();

    protected:

    };

}
#endif /* Game_hpp */
