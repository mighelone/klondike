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
        return is_card_lower_one(card) and is_color_different(card);
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

    bool Stack::is_card_lower_one(const Card &card) const
    {
        int value_to_add=Card::value_to_int(card.get_value());
        int last_value=Card::value_to_int(visible.back().get_value());
        //std::cout << value_to_add << ": " << last_value << std::endl;
        return value_to_add == (last_value-1);
    }

    bool Stack::is_color_different(const Card &card) const
    {
        return card.is_red() xor visible.back().is_red();
    }


} // edn namespace klondike
