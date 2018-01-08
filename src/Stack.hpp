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
#include "Card.hpp"

namespace klondike {

    class Stack {
    private:
        std::vector<Card> hidden;
        std::vector<Card> visible;
    public:
        // push a card to the hidden cards
        void push_hidden(Card card);
        bool should_turn_card() const;
        void turn_card();
        bool can_add_card(Card card);
        void add_card_visible(Card card);
        Card::CardValue last_value() const;
        Card::RankValue last_rank() const;
        Card last_visible() const;
    protected:
    };

} // end namespace klondike
#endif /* Stack_hpp */
