//
//  Game.hpp
//  klondike
//
//  Created by <author> on 06/01/2018.
//
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>

#include "Deck.hpp"
#include "Card.hpp"

namespace klondike{

class Game {
private:
    DeckVector stock;
    DeckVector discard;
    std::vector<DeckVector> piles;
public:
    Game();
    ~Game();
    void move_to_pile();

protected:

};

}
#endif /* Game_hpp */
