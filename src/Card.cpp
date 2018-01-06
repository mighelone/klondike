//
//  Card.cpp
//  exercise
//
//  Created by <author> on 05/01/2018.
//
//

#include "Card.hpp"

namespace klondike {

Card::Card(RankValue r, CardValue v): rank(r), value(v){}
Card::Card(int r, int v): Card(static_cast<RankValue>(r), static_cast<CardValue>(v)){}
Card::~Card() {}

std::ostream& operator<< (std::ostream& stream, const Card & c)
{
    stream << Card::VALUE_NAMES[c.value-1] << " of " << Card::RANK_NAMES[c.rank];
    return stream;
}

const std::string Card::RANK_NAMES[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const std::string Card::VALUE_NAMES[] = {
    "Ace",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Jack",
    "Queen",
    "King"};

} // end namespace klondike
