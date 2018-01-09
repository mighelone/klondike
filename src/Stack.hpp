//
//  Stack.hpp
//  klondike
//
//  Created by <author> on 07/01/2018.
//
//

#ifndef Stack_hpp
#define Stack_hpp

#include <vector>
#include <exception>
#include "Card.hpp"

// for gtest
#define GTEST
#ifdef GTEST
#include "gtest/gtest_prod.h"
#endif

namespace klondike {
    class StackPushVisibleException: public std::exception
    {
    public:
        char const * what()
        {
            return "Stack push visible exception";
        }
    };

    class StackPushHiddenException: public std::exception
    {
    public:
        char const * what()
        {
            return "Stack push visible exception";
        }
    };

    class Stack {
    private:
        std::vector<Card> hidden;
        std::vector<Card> visible;
        #ifdef GTEST
        FRIEND_TEST(StackTest, pop_visible_cards);
        FRIEND_TEST(StackTest, pop_visible_cards_n);

        #endif
    public:
        // push a card to the hidden cards
        void push_hidden(Card card) throw(StackPushHiddenException);
        bool should_turn_card() const;
        void turn_card();
        bool can_add_card(Card card);
        void push_visible(Card card) throw(StackPushVisibleException);
        void push_visible(const std::vector<Card> &cards) throw(StackPushVisibleException);
        Card::CardValue last_value() const;
        Card::RankValue last_rank() const;
        Card last_visible() const;
        bool is_card_lower_one(const Card &card) const;
        bool is_color_different(const Card &card) const;
        std::vector<Card> pop_visible_cards();
        std::vector<Card> pop_visible_cards(int n);

    protected:
    };

} // end namespace klondike
#endif /* Stack_hpp */
