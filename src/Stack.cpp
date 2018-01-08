//
//  Stack.cpp
//  klondike
//
//  Created by <author> on 07/01/2018.
//
//

#include "Stack.hpp"

namespace klondike {

    void Stack::push_hidden(Card card)
    {
        hidden.push_back(card);
    }

    bool Stack::should_turn_card() const
    {
        return (visible.empty() and !hidden.empty());
    }

    void Stack::turn_card()
    {
        if (should_turn_card())
        {
            Card c = hidden.back();
            hidden.pop_back();
            visible.push_back(c);
        }
    }

    bool Stack::can_add_card(Card card)
    {
        int value_card=static_cast<Card::CardValue>(card.get_value());
        int stack_card=static_cast<Card::CardValue>(last_value());
        bool value_is_lower_one = value_card == (stack_card-1);
        bool color_is_opposite = card.is_red() xor visible.back().is_red();

        return value_is_lower_one and color_is_opposite;
    }

    void Stack::add_card_visible(Card card)
    {
        visible.push_back(card);
    }


    Card::CardValue Stack::last_value() const
    {
        return visible.back().get_value();
    }

    Card::RankValue Stack::last_rank() const
    {
        return visible.back().get_rank();
    }

    Card Stack::last_visible() const
    {
        return visible.back();
    }



} // edn namespace klondike
