#include <iostream>

// google tests
#include "gtest/gtest.h"

#include "Foundation.hpp"

namespace klondike {

    Card::RankValue rank = Card::Hearts;
    Card ace(rank, Card::Ace);
    Card two(rank, Card::Two);

    class FoundationTest: public ::testing::Test
    {
    public:
        Foundation found;
        virtual void SetUp() {
            found.push_front(ace);
        };
        virtual void TearDown() {};
    };

    TEST(FoundationTestEmpty, can_add_card)
    {
        Foundation found;
        EXPECT_TRUE(found.can_add_card(ace));
        EXPECT_FALSE(found.can_add_card(Card(rank, Card::Two)));
    }

    TEST_F(FoundationTest, rank_is_equal)
    {
        EXPECT_TRUE(found.rank_is_equal(two));
        EXPECT_FALSE(found.rank_is_equal(Card(Card::Spades, 1)));
    }

    TEST_F(FoundationTest, can_add_card)
    {
        EXPECT_TRUE(found.can_add_card(two));
        EXPECT_FALSE(found.can_add_card(Card(rank, Card::Three)));
    }

    TEST_F(FoundationTest, push_front)
    {
        found.push_front(two);
        EXPECT_TRUE(two == found.top());
        Card three(rank, Card::Three);
        found.push_front(Card(rank, Card::Three));
        EXPECT_TRUE(three == found.top());
    }

}  //end namespace klondike

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  //Card card(0, 1);
}
