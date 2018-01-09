//
//  Game.cpp
//  klondike
//
//  Created by <author> on 06/01/2018.
//
//

#include "Game.hpp"
#include <algorithm>

namespace klondike
{
    Game::Game(): stacks(7)  {
        // init and shuffle deck
        deck.init_cards();
        deck.shuffle_cards();

        for (int i=0; i < stacks.size(); i++)
        {
            for (int j=0; j < i+1; j++)
            {
                stacks[i].push_hidden(deck.pop());
            }
            stacks[i].turn_card();
        }
    }
    Game::~Game() {}

    void Game::print() const
    {
        print_deque();
        print_stacks();
    }

    void Game::print_stacks() const
    {
        int rows = 0;

        // calc the max length of the stacks
        //std::vector<size_t> stack_size;
        size_t max_size = 0;
        for (auto stack: stacks)
        {
            //stack_size.push_back(stack.size());
            size_t stack_size = stack.hidden_size() + stack.visible_size();
            if (stack_size > max_size)
                max_size = stack_size;
        }

        for (int i=0; i<max_size; i++)
        {
            std::cout << "\t";
            for (auto stack: stacks)
            {
                if (i < stack.hidden_size())
                {
                    //std::cout << stack.get_hidden()[i] << "\t";
                    std::cout << "[]" << "\t";
                }
                else if (i < stack.hidden_size() + stack.visible_size())
                {
                    std::cout << stack.get_visible()[i-stack.hidden_size()] << "\t";
                }
                else
                {
                    std::cout << "  " << "\t";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void Game::print_deque() const
    {
        std::cout <<  std::endl;
        for (int i=0; i<stacks.size()-1; i++)
        {
            std::cout << "  " << "\t";
        }
        std::cout << "[]" << "\t";
        if (discard.empty())
            std::cout << "[]" << "\t";
        else
            std::cout << discard.back() << "\t";
        std::cout << std::endl << std::endl;
    }

    void Game::move(int from, int n, int to)
    {
        // check if the move can be done
        Stack &from_stack = stacks[from];
        Card connect_card = from_stack.get_visible()[from_stack.visible_size()-n];
        Stack &to_stack = stacks[to];
        //
        if (to_stack.can_add_card(connect_card))
        {
            //std::vector<Card> popped_cards = from_stack.pop_visible_cards(n);
            to_stack.push_visible(from_stack.pop_visible_cards(n));
        }
        //if (from_stack.visible_size()==0 and from_stack.hidden_size()!=0)
        if (from_stack.should_turn_card())
            from_stack.turn_card();

    }
}
