//
//  Card.hpp
//  exercise
//
//  Created by <author> on 05/01/2018.
//
//

#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include <vector>
#include <string>
#include <map>


namespace klondike {

class Card {
public:
    enum CardValue {
        Ace=1,
        Two=2,
        Three=3,
        Four=4,
        Five=5,
        Six=6,
        Seven=7,
        Jack=8,
        Queen=9,
        King=10
     };
    enum Rank {Clubs, Diamonds, Hearts, Spades};
private:
    Rank rank;
    CardValue value;
public:
    Card(Rank r=Clubs, CardValue v=Ace);
    Card(int r, int v);
    ~Card();
    friend std::ostream& operator<< (std::ostream& stream, const Card & c);
    //static constexpr std::string RANK_NAMES[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    //static constexpr int RANK_NAMES[] = {1, 2, 3, 4};
    static const std::string RANK_NAMES[];
    static const std::string VALUE_NAMES[];
protected:

};

} // end namespace klondike


#endif /* Card_hpp */
