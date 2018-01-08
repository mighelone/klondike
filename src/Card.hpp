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
        Card(int r=0, int v=1);
        Card(RankValue r=Clubs, int v=1);
        Card(int r=0, CardValue v=Ace);
        ~Card();
        friend std::ostream& operator<< (std::ostream& stream, const Card & c);
        CardValue get_value() const {return value;}
        RankValue get_rank() const {return rank;}
        static std::string rank_to_string(const RankValue & rank);
        static std::string value_to_string(const CardValue & value);
        static int rank_to_int(const RankValue & rank){
            int i = static_cast<RankValue>(rank);
            return i;}
        static int value_to_int(const CardValue & value){return static_cast<CardValue>(value);}
        static RankValue int_to_rank(int rank){return static_cast<RankValue>(rank);}
        static CardValue int_to_value(int value){return static_cast<CardValue>(value);}

        bool is_red() const;
        bool is_black() const;

        bool operator==(Card card);

    protected:

    };

    // equal operatore between enum and int
    bool operator==(Card::CardValue value1, int value2);
    bool operator==(int value1, Card::CardValue value2);
    bool operator==(Card::RankValue value1, int value2);
    bool operator==(int value1, Card::RankValue value2);

    //Card::CardValue operator++ (Card::CardValue);
    std::ostream& operator<< (std::ostream& stream, Card::RankValue rank);
    std::ostream& operator<< (std::ostream& stream, Card::CardValue value);

} // end namespace klondike


#endif /* Card_hpp */
