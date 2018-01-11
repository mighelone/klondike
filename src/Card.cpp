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
    Card::Card(RankValue r, int v): Card(r, int_to_value(v)){};
    Card::Card(int r, CardValue v): Card(int_to_rank(r), v){};
    //Card::Card(): Card(Clubs, Ace) {};
    Card::~Card() {}

    std::ostream& operator<< (std::ostream& stream, const Card & c)
    {
        if (c.is_red())
            stream << RED_;
        else
            stream << BLUE_;
        stream << Card::VALUE_NAMES[c.value-1] << Card::RANK_NAMES[c.rank];
        if (c.is_red())
            stream << _RED;
        else
            stream << _BLUE;
        return stream;
    }

    //const std::string Card::RANK_NAMES[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    //const std::string Card::RANK_NAMES[] = {"C", "D", "H", "S"};
    const std::string Card::RANK_NAMES[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
    const std::string Card::VALUE_NAMES[] = {
        // "Ace",
        // "Two",
        // "Three",
        // "Four",
        // "Five",
        // "Six",
        // "Seven",
        // "Jack",
        // "Queen",
        // "King"
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
    };

    bool Card::is_red() const
    {
        return rank == RankValue::Diamonds or rank == RankValue::Hearts;
    }

    bool Card::is_black() const
    {
        return !is_red();
    }

    std::string Card::rank_to_string(const Card::RankValue &rank)
    {
        return RANK_NAMES[rank];
    }

    std::string Card::value_to_string(const Card::CardValue &value)
    {
        return VALUE_NAMES[value-1];
    }

    bool Card::operator==(Card card) const
    {
        return rank == card.rank and value == card.value;
    }

    bool operator==(Card::CardValue value1, int value2)
    {
        return Card::value_to_int(value1) == value2;
    }

    bool operator==(int value1, Card::CardValue value2)
    {
        return value2 == value1;
    }
    bool operator==(Card::RankValue value1, int value2)
    {
        return Card::rank_to_int(value1) == value2;
    }

    bool operator==(int value1, Card::RankValue value2)
    {
        return value2 == value1;
    }

    std::ostream& operator<< (std::ostream& stream, Card::RankValue rank)
    {
        stream << Card::rank_to_string(rank);
        return stream;
    }

    std::ostream& operator<< (std::ostream& stream, Card::CardValue value)
    {
        stream << Card::value_to_string(value);
        return stream;
    }
} // end namespace klondike
