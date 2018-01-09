#include <iostream>

// google tests
#include "gtest/gtest.h"

#include "Stack.hpp"
#include "Card.hpp"


namespace klondike{

    const Card last_visible_card(Card::Spades, Card::Jack);
    const Card card_add(Card::Hearts, Card::Seven);
    const Card card_cannot_add(Card::Clubs, Card::Five);

    class StackTest: public ::testing::Test
    {
    public:

    public:
        Stack stack;
        virtual void SetUp() {
            // initialize hidden
            stack.push_hidden(Card(Card::Clubs, Card::King));
            stack.push_hidden(Card(Card::Hearts, Card::Seven));
            stack.push_hidden(Card(Card::Diamonds, Card::Three));
            stack.push_hidden(last_visible_card);
            // turn card
            stack.turn_card();
        }
    };

    TEST_F(StackTest, last_visible)
    {
        EXPECT_TRUE(last_visible_card == stack.last_visible());
    }

    TEST_F(StackTest, is_card_lower_one)
    {
        //EXPECT_TRUE(stack.is_card_lower_one(card_add));
        //std::cout << "Last card:" << stack.last_visible() << " to int=" << Card::value_to_int(stack.last_visible().get_value()) << "\n";
        //std::cout << "Card to add:" << card_add <<  " to int=" << Card::value_to_int(card_add.get_value()) << "\n";
        EXPECT_TRUE(stack.is_card_lower_one(card_add));
        EXPECT_FALSE(stack.is_card_lower_one(card_cannot_add));
    }

    TEST_F(StackTest, is_color_different)
    {
        EXPECT_TRUE(stack.is_color_different(card_add));
        EXPECT_FALSE(stack.is_color_different(card_cannot_add));
    }

    TEST_F(StackTest, can_add_card)
    {
        EXPECT_TRUE(stack.can_add_card(card_add));
        EXPECT_FALSE(stack.can_add_card(card_cannot_add));
    }

    TEST_F(StackTest, add_card)
    {
        //stack.push_visible(Card(Card::Spades, Card::Ace));
        stack.push_visible(card_add);
        EXPECT_TRUE(stack.last_visible()==card_add);

        ASSERT_THROW(stack.push_visible(card_cannot_add), StackPushVisibleException);
    }

    TEST_F(StackTest, push_hidden)
    {
        // test if push_hidden throw an exception if the visible is not empty
        EXPECT_THROW(stack.push_hidden(card_cannot_add), StackPushHiddenException);
    }

    TEST_F(StackTest, pop_visible_cards)
    {
        //Card card(Card::Diamonds, Card::Queen);

        stack.push_visible(card_add);

        int size_visible = stack.visible.size();

        std::vector<Card> popped = stack.pop_visible_cards();
        EXPECT_EQ(size_visible, popped.size());
        EXPECT_TRUE(popped.back() == card_add);
    }

    TEST_F(StackTest, pop_visible_cards_n)
    {
        stack.push_visible(card_add);
        // push three more
        for (int i=0; i< 3; i++)
        {
            Card last = stack.last_visible();
            //Card::RankValue rank = last.is_red() ? Card::Spades : Card::Hearts;
            Card card = Card(last.is_red() ? Card::Spades : Card::Hearts,
                Card::value_to_int(last.get_value())-1);
            stack.push_visible(card);
        }
        int n = 3;
        int size = stack.visible.size();
        //std::cout << "Visible size=" << stack.visible.size() << std::endl;
        std::vector<Card> popped = stack.pop_visible_cards(n);
        EXPECT_EQ(popped.size(), n);
        EXPECT_EQ(stack.visible.size(), size-n);

        // check if the popped cards can be pushed again
        stack.push_visible(popped);
        EXPECT_EQ(stack.visible.size(), size);
    }
} // end namespace klondike

using namespace klondike;


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
