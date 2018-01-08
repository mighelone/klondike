//
//  Foundations.hpp
//  klondike
//
//  Created by <author> on 08/01/2018.
//
//

#ifndef Foundation_hpp
#define Foundation_hpp

#include <stack>
#include "Card.hpp"

namespace klondike{
    class Foundation {
        //Card::RankValue last_value;
    private:
        std::stack<Card> cards;
    public:
        bool empty() const;
        bool can_add_card(Card card) const;
        Card last() const;
        void push_front(const Card &card);
        //Foundations();
        //~Foundations();
    protected:

    };
}

#endif /* Foundation_hpp */
