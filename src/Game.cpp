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
    Game::Game(): stacks(N_STACKS)  {
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
            for (int i=0; i<4; i++)
            {
                //std::cout << "Add foundation of " << Card::rank_to_string(Card::int_to_rank(i)) << "\n";
                foundations.insert(std::make_pair(Card::int_to_rank(i), Foundation()));
            }
        }
    }
    Game::~Game() {}

    void Game::print() const
    {
        print_deque();
        print_foundations();
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

    void Game::print_foundations() const{
        std::cout <<  std::endl;
        std::cout << "  " << "\t";
        for (auto it=foundations.begin(); it!=foundations.end(); it++)
        {
            if (it->second.empty()){
                std::cout << "[]" << "\t";
            }
            else {
                std::cout << it->second.top() << "\t";
            }
        }
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
            //if (from_stack.visible_size()==0 and from_stack.hidden_size()!=0)
            if (from_stack.should_turn_card())
                from_stack.turn_card();

        }
        else
            std::cerr << "Cannot move from stack " << from << " to " << to << "\n";
    }

    void Game::move(int from)
    {
        // move a card from a stack to its foundation
        Stack &from_stack = stacks[from];
        const Card & last_card = from_stack.last_visible();
        Card::RankValue rank = last_card.get_rank();
        //

        if (foundations.find(rank) != foundations.end())
        {
            Foundation &f = foundations[last_card.get_rank()];
            if (f.can_add_card(last_card))
            {
                //Card popped =
                f.push_front(from_stack.pop_visible_cards(1)[0]);
                if (from_stack.should_turn_card())
                    from_stack.turn_card();
            }
            else {
                std::cerr << "Can add " << last_card << "to its foundation: " << f.top() << "\n";
            }
        }
        else
        {
            // throw an error
            std::cout << "Here !" << "\n";
        }
    }

    void Game::print_prompt() const
    {
        std::cout << "Commands:" << "\n";
        std::cout << "(1) move cards from one stack to another" << "\n";
        std::cout << "(2) move a card from one stack to its foundation" << "\n";
        std::cout << "(3) move a card from discard deck to a stack" << "\n";
        std::cout << "(4) move a card from discard deck to its foundation" << "\n";
        std::cout << "(5) move a card from deck to discard" << "\n";
    }

    void Game::prompt()
    {
        int command;
        std::cin >> command;
        switch (command)
        {
        case 1:
            {
                std::cout << "From which stack:";
                int from, n, to;
                std::cin >> from;
                std::cout << "How many cards:";
                std::cin >> n;
                std::cout << "To which stack:";
                std::cin >> to;
                try {
                    move(from, n, to);
                }
                catch (...)
                {
                    std::cout << "Cannot move from " << from << " to " << to << "\n";
                }
            }
            break;

        case 2:
            {
                std::cout << "From which stack:";
                int from;
                std::cin >> from;
                try{
                    move(from);
                }
                catch (...)
                {
                    std::cout << "Cannot move from " << from << " to the foundation"  << "\n";
                }
            }
            break;

        case 3:
            {
                std::cout << "To which stack:" << "\n";
                int to;
                std::cin >> to;
                try{
                    move_from_discard(to);
                }
                catch (...)
                {
                    std::cerr << "Cannot move discarded card to " << to << "\n";
                }
            }
            break;
        case 4:
            {
                try{
                    move_from_discard();
                }
                catch (...)
                {
                    const Card &discard_card = discard.back();
                    std::cerr << "Cannot move discarded card to its foundation" << "\n";
                    std::cerr << "Discarded card is " << discard_card <<  "\n";
                    std::cerr << "Last card in " << Card::rank_to_string(discard_card.get_rank()) ;
                    std::cerr << "is " << foundations[discard_card.get_rank()].top() << "\n";
                }
            }
            break;
        case 5:
            {
                move_to_discard();
            }
            break;
        }
    }

    void Game::move_from_discard(int n)
    {
        const Card &card = discard.back();
        Stack & to_stack = stacks[n];
        if (to_stack.can_add_card(card))
        {
            to_stack.push_visible(discard.pop());
        }
    }

    void Game::move_from_discard()
    {
        const Card &card = discard.back();
        Card::RankValue rank = card.get_rank();
        Foundation& to_found = foundations[rank];
        if (to_found.can_add_card(card))
        {
            to_found.push_front(discard.pop());
        }
        else
        {
            std::cerr << "Cannot move card from discard to foundation" << "\n";
        }
    }

    void Game::move_to_discard(){
        if (deck.empty())
        {
            while (!discard.empty()){
                deck.push(discard.pop());
            }
        }
        discard.push(deck.pop());
    }
}
