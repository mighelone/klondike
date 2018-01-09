//
//  Game.cpp
//  klondike
//
//  Created by <author> on 06/01/2018.
//
//

#include "Game.hpp"

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
        print_stacks();
    }

    void Game::print_stacks() const
    {
        int rows = 0;
        std::vector<bool> stack_end(stacks.size(), false);
        for (int i=0; i<10; i++)
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
    }

}
