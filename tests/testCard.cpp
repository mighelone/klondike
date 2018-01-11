///
///
///

#include <iostream>

// google tests
#include "gtest/gtest.h"

#include "Card.hpp"

using namespace klondike;


TEST(CardTest, ctor)
{
    Card::RankValue rank = Card::Clubs;
    Card::CardValue value = Card::Ace;
    Card card(rank, value);
    EXPECT_EQ(card.get_rank(), rank);
    EXPECT_EQ(card.get_value(), value);
}

TEST(CardTest, ctor_all_int)
{

    // create card with int
    Card card(0, 1);
    EXPECT_EQ(card.get_rank(), Card::Clubs);
    EXPECT_EQ(card.get_value(), Card::Ace);
}

TEST(CardTest, ctor_rank_int)
{

    // create card with int
    //Card card(0, Card::Ace);

    EXPECT_TRUE(Card(0, Card::Ace) == Card(Card::Clubs, Card::Ace));
    //EXPECT_EQ(card.get_value(), Card::Ace);
}

TEST(CardTest, ctor_value_int)
{

    // create card with int
    //Card card(0, Card::Ace);

    EXPECT_TRUE(Card(Card::Clubs, 1) == Card(Card::Clubs, Card::Ace));
    //EXPECT_EQ(card.get_value(), Card::Ace);
}

TEST(CardTest, ctorInt2)
{

    // create card with int
    Card card(0, 1);
    Card card1(Card::Clubs, Card::Ace);
    EXPECT_EQ(card.get_rank(), card1.get_rank());
    EXPECT_EQ(card.get_value(), card1.get_value());
    //EXPECT_EQ(card, card1);
}

TEST(CardTest, color)
{
    Card card1(Card::Clubs, Card::Ace);
    EXPECT_TRUE(card1.is_black());
    EXPECT_FALSE(card1.is_red());
}

TEST(CardTest, rank_to_string)
{
    EXPECT_EQ(Card::rank_to_string(Card::Clubs), "Clubs");
    EXPECT_EQ(Card::rank_to_string(Card::Diamonds), "Diamonds");
    EXPECT_EQ(Card::rank_to_string(Card::Spades), "Spades");
    EXPECT_EQ(Card::rank_to_string(Card::Hearts), "Hearts");
}

TEST(CardTest, value_to_string)
{
    EXPECT_EQ(Card::value_to_string(Card::Ace), "Ace");
    EXPECT_EQ(Card::value_to_string(Card::Queen), "Queen");
    EXPECT_EQ(Card::value_to_string(Card::King), "King");
    //EXPECT_EQ(Card::rank_to_string(Card::Diamonds), "Diamonds");
    //EXPECT_EQ(Card::rank_to_string(Card::Spades), "Spades");
    //EXPECT_EQ(Card::rank_to_string(Card::Hearts), "Hearts");
}

TEST(CardTest, int_conversion)
{
    //int rank = Card::rank_to_int(Card::Ace);
    //Card::RankValue rank = Card::int_to_rank(1)
    EXPECT_EQ(Card::int_to_rank(0),  Card::Clubs);
    EXPECT_EQ(Card::int_to_rank(1),  Card::Diamonds);
    EXPECT_EQ(Card::int_to_value(1),  Card::Ace);
    //EXPECT_EQ(Card::rank_to_int(Card::Ace), 1);
    //int x = static_cast<Card::CardValue>(Card::Ace);
    EXPECT_EQ(Card::value_to_int(Card::Ace), 1);
    EXPECT_EQ(Card::rank_to_int(Card::Diamonds), 1);
}

TEST(CardTest, equal)
{
    //std::cout << "Print Ace: " << Card::Ace << "\n";
    //std::cout << "Print Clubs: " << Card::Clubs << "\n";
    EXPECT_TRUE(Card::Ace == 1);
    EXPECT_TRUE(1 == Card::Ace);
    EXPECT_TRUE(Card::Clubs == 0);
    EXPECT_TRUE(0 == Card::Clubs);
    EXPECT_TRUE(Card(Card::Clubs, Card::Two) == Card(0, 2));
}

TEST(CardTest, get_rank_int)
{
    Card card(0, 1);
    EXPECT_EQ(card.get_rank_int(), 0);
}

TEST(CardTest, get_value_int)
{
    Card card(0, 1);
    //std::cout << card << "\n";
    EXPECT_EQ(card.get_value_int(), 1);

    std::cout << Card(Card::Spades, Card::King) << "\n";
    std::cout << Card(Card::Hearts, Card::Queen) << "\n";
    std::cout << Card(Card::Clubs, Card::Jack) << "\n";
}


// TEST(CardTest, operators)
// {
//     Card::CardValue value = Card::Ace;
//     //++value;
//     std::cout << Card::value_to_string(value) << std::endl;
//     //EXPECT_TRUE(value == Card::Two);
// }


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  //Card card(0, 1);
}
