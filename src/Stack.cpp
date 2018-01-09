//
//  Stack.cpp
//  klondike
//
//  Created by <author> on 07/01/2018.
//
//

#include "Stack.hpp"

namespace klondike {

    void Stack::push_hidden(Card card) throw(StackPushHiddenException)
    {
        if (!visible.empty())
        {
            throw StackPushHiddenException();
        }
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

    void Stack::push_visible(Card card) throw(StackPushVisibleException)
    {
        if (!can_add_card(card))
        {
            throw StackPushVisibleException();
        }
        visible.push_back(card);
    }

    void Stack::push_visible(const std::vector<Card> &cards) throw(StackPushVisibleException)
    {
        // push the cards in the given order
        for (auto card: cards)
        {
            push_visible(card);
        }
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

    std::vector<Card> Stack::pop_visible_cards()
    {
        std::vector<Card> popped;
        for (auto card: visible)
        {
            popped.push_back(card);
        }
        visible.clear(); // clear visible
        return popped;
    }

    // pop the last n cards
    std::vector<Card> Stack::pop_visible_cards(int n)
    {
        std::vector<Card> popped(n);
        if (n > visible.size())
            throw std::exception();
        int size_n = visible.size() - n;
        for (int i=0; i < n; i++)
        {
            popped[i] = visible[size_n+i];
            //std::cout << "Pop i=" << size_n+i << " "<< visible[size_n+i]  << "\n";
        }
        // delete
        visible.erase(visible.begin()+size_n, visible.end());
        return popped;
    }



} // edn namespace klondike
