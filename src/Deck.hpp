//
//  Deck.hpp
//  klondike
//
//  Created by <author> on 06/01/2018.
//
//

#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include <deque>
#include "Card.hpp"

namespace klondike {

typedef std::vector<Card> DeckVector;


// // create a deck of 52 cards
// DeckVector create_deck();
//
// // shuffle the deck
// void shuffle_deck(DeckVector &deck);


// Card Deck
class Deck
{
private:
    std::deque<Card> cards;
public:
    Deck();
    void init_cards();
    void shuffle_cards();
    //~Deck();
    Deck(const Deck& other) = default;
    Deck(Deck&& other) = default;
    Card pop();
    void push(const Card & card);
    int size() const;

    bool empty() const;
    Card back() const {return cards.back();}
    //Deck& operator=(const Deck& other) = default;
    //Deck& operator=(Deck&& other) = default;
};

}
#endif /* Deck_hpp */
