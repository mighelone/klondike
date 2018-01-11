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
        // test move from stack to stack
        Stack & st0 = game.stacks[0];
        Stack & st1 = game.stacks[1];
        st0.pop_visible_cards();
        st1.pop_visible_cards();
        EXPECT_EQ(game.stacks[0].visible_size(), 0);
        EXPECT_EQ(game.stacks[1].visible_size(), 0);
        //std::cout << "Empty stacks" << "\n";
        st1.push_visible(Card(get_red(), Card::King));
        //std::cout << "Add king" << "\n";
        st0.push_visible(Card(get_red(), Card::King));
        st0.push_visible(Card(get_black(), Card::Queen));
        //std::cout << "Add queen" << "\n";
        st0.push_visible(Card(get_red(), Card::Jack));
        st0.push_visible(Card(get_black(), Card::Ten));
        //std::cout << "Fill stacks" << "\n";
        EXPECT_EQ(game.stacks[1].visible_size(), 1);
        EXPECT_EQ(game.stacks[0].visible_size(), 4);

        // move 3 cards from stack 0 to
        //std::cout << "Move 3 cards from stack 0 to 1" << "\n";
        game.move(0, 3, 1);
        // check that stack 1 has 4 cards
        EXPECT_EQ(game.stacks[1].visible_size(), 4);
        // check that stack 0 has no card
        EXPECT_EQ(game.stacks[0].visible_size(), 1);
    }

    TEST_F(GameTest, move_king)
    {
        // test if a king can be moved to an empty stack
        Stack & st0 = game.stacks[0];
        Stack & st1 = game.stacks[1];
        st0.pop_visible_cards();
        st1.pop_visible_cards();
        Card king = Card(get_red(), Card::King);
        st0.push_visible(king);
        game.move(0, 1, 1);
        EXPECT_EQ(game.stacks[0].visible_size(), 0);
        EXPECT_EQ(game.stacks[1].visible_size(), 1);
        EXPECT_TRUE(game.stacks[1].last_visible() == king);
    }

    TEST_F(GameTest, move_to_foundation)
    {
        // test if a card can be moved from a stack to its foundation
        Stack & st0 = game.stacks[0];
        st0.pop_visible_cards();

        Card ace = Card(Card::Hearts, Card::Ace);
        st0.push_hidden(ace);
        st0.turn_card();

        game.move(0);
        //std::cout << "Moved" << "\n";
        EXPECT_TRUE(ace == game.foundations[ace.get_rank()].top());
        EXPECT_TRUE(st0.empty_visible());


        //st0.push_hidden()
        Card two = Card(Card::Hearts, Card::Two);
        st0.push_hidden(two);
        st0.turn_card();
        game.move(0);
        EXPECT_TRUE(two == game.foundations[Card::Hearts].top());
        EXPECT_TRUE(st0.empty_visible());
    }

    TEST_F(GameTest, move_from_discard)
    {
        Stack & st0 = game.stacks[0];
        st0.pop_visible_cards();
        Card seven(Card(get_red(), Card::Seven));
        Card six(Card(get_black(), Card::Six));
        st0.push_hidden(seven);
        st0.turn_card();
        game.discard.push(six);
        //
        game.move_from_discard(0);
        EXPECT_TRUE(six==st0.last_visible());
        EXPECT_FALSE(six==game.discard.back());
    }

    TEST_F(GameTest, move_from_discard_f)
    {

    }

}//namespace klondike

int main(int argc, char* argv[])
{

    // klondike::Game game;
    // game.print();
    // game.print_prompt();
    // game.prompt();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
