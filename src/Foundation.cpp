//
//  Foundations.cpp
//  klondike
//
//  Created by <author> on 08/01/2018.
//
//

#include "Foundation.hpp"
namespace klondike{

    bool Foundation::empty() const
    {
        return cards.empty();
    }

    bool Foundation::can_add_card(Card card) const
    {
        if (empty())
        {
            if (card.get_value() == Card::Ace)
                return true;
        }
        const Card last_card = cards.top();
        bool rank_is_equal = last_card.get_rank() == card.get_rank();
        bool is_next_value = static_cast<Card::CardValue>(last_card.get_value()) == (static_cast<Card::CardValue>(card.get_value()) + 1);
        return rank_is_equal and is_next_value;
    }

    Card Foundation::last() const
    {
        return cards.top();
    }

    void Foundation::push_front(const Card &card)
    {
        if (can_add_card(card))
        {
            cards.push(card);
        }
        else
        {
            std::cout << "Cannot add " << card << "to the Fondation";
        }
    }
}
