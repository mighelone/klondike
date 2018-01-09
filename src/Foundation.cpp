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

    bool Foundation::can_add_card(const Card &card) const
    {
        if (empty())
        {
            if (card.get_value() == Card::Ace)
                return true;
            else
                return false;
        }
        const Card last_card = cards.top();
        if (rank_is_equal(card))
        {
            return last_card.get_value_int() == card.get_value_int() - 1;
        }
        else
            return false;
    }

    bool Foundation::rank_is_equal(const Card &card) const
    {
        return cards.top().get_rank() == card.get_rank();
    }

    Card Foundation::top() const
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
