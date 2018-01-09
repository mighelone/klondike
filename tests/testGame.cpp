#include "Game.hpp"
#include "Stack.hpp"
#include <map>

// google tests
#include "gtest/gtest.h"

namespace klondike{
    class GameTest: public ::testing::Test
    {
    public:
        Game game;
    };

    Card::RankValue get_red()
    {
        return Card::Hearts;
    }

    Card::RankValue get_black()
    {
        return Card::Spades;
    }

    TEST_F(GameTest, move)
    {
        Stack & st0 = game.stacks[0];
        Stack & st1 = game.stacks[1];
        st0.pop_visible_cards();
        st1.pop_visible_cards();
        EXPECT_EQ(game.stacks[0].visible_size(), 0);
        EXPECT_EQ(game.stacks[1].visible_size(), 0);
        st1.push_visible(Card(get_red(), Card::King));
        st0.push_visible(Card(get_black(), Card::Queen));
        st0.push_visible(Card(get_red(), Card::Jack));
        st0.push_visible(Card(get_black(), Card::Ten));
        EXPECT_EQ(game.stacks[1].visible_size(), 1);
        EXPECT_EQ(game.stacks[0].visible_size(), 3);

        game.move(0, 3, 1);
        EXPECT_EQ(game.stacks[1].visible_size(), 4);
        EXPECT_EQ(game.stacks[0].visible_size(), 0);
        game.print();
    }

    TEST_F(GameTest, move_to_pile)
    {
        Stack & st0 = game.stacks[0];
        st0.pop_visible_cards();
        Card ace = Card(Card::Hearts, Card::Ace);
        st0.push_visible(ace);
        game.move(0);
        EXPECT_TRUE(ace == game.foundations[Card::Hearts].top());
        EXPECT_TRUE(st0.empty_visible());
        Card two = Card(Card::Hearts, Card::Two);
        st0.push_visible(two);
        game.move(0);
        EXPECT_TRUE(two == game.foundations[Card::Hearts].top());
        EXPECT_TRUE(st0.empty_visible());
    }

}//namespace klondike

int main(int argc, char* argv[])
{

    klondike::Game game;
    game.print();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
