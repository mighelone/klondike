//
//  Deck.cpp
//  klondike
//
//  Created by <author> on 06/01/2018.
//
//

#include "Deck.hpp"
#include <algorithm>  // random_shuffle

namespace klondike {

    Deck::Deck()
    {
        // create cards
        init_cards();
        shuffle_cards();
    }

    // init a new Deck with the whole set of cards
    void Deck::init_cards()
    {
        //
        if (!cards.empty())
        {
            cards.clear();
        }
        for (int rank=0; rank<4; rank++)
        {
            for (int value=1; value<=10; value++)
            {
                cards.push_back(Card(rank, value));
            }
        }
    }

    // shuffle the cards
    void Deck::shuffle_cards()
    {
        std::random_shuffle (cards.begin(), cards.end());
    }

    Card Deck::pop()
    {
        Card c = cards.back();
        cards.pop_back();
        return c;
    }

    void Deck::push(const Card & card) {
        cards.push_front(card);
    }

    int Deck::size() const
    {
        return (int) cards.size();
    }

}
