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
    enum RankValue {Clubs, Diamonds, Hearts, Spades};
private:
    RankValue rank;
    CardValue value;
    static const std::string RANK_NAMES[];
    static const std::string VALUE_NAMES[];
public:
    Card(RankValue r=Clubs, CardValue v=Ace);
    Card(int r, int v);
    ~Card();
    friend std::ostream& operator<< (std::ostream& stream, const Card & c);
    CardValue get_value() const {return value;}
    RankValue get_rank() const {return rank;}

    bool is_red() const;
    bool is_black() const;

protected:

};

} // end namespace klondike


#endif /* Card_hpp */
