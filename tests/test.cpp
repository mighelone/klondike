#include <iostream>
#include <string>
#include <deque>



#include "Card.hpp"
#include "Deck.hpp"
#include "Stack.hpp"
#include "Foundation.hpp"

using namespace klondike;
using namespace std;


int main(int argc, char* argv[])
{
    Deck deck;
    Stack stack;
    for (int i=0; i<5; i++)
    {
        stack.push_hidden(deck.pop());
    }
    Foundation fondation;
    //
    // test stack
    //
    stack.turn_card();
    cout << endl;

    try
    {
        stack.push_visible(Card(Card::Spades, Card::King));
    }
    catch (StackPushVisibleException &e)
    {
        /* code */
        cout << e.what() << endl;
    }


    // while (!deck.empty())
    // {
    //     //cout << endl << endl << endl << endl << endl << endl << endl << endl;
    //     for (int i=0; i<2; i++)
    //         cout << endl;
    //     cout << "Last visible card is " << stack.last_visible() << endl;
    //     Card card = deck.pop();
    //     cout << "New card is " << card <<endl;
    //     if (stack.can_add_card(card))
    //     {
    //         cout << "Add to the stack" << endl;
    //         stack.add_card_visible(card);
    //     }
    //     else
    //     {
    //         if (fondation.empty() and card.get_value() == Card::Ace)
    //         {
    //             cout << "Create a new fondation with " << Card::rank_to_string(card.get_rank()) << endl;
    //         }
    //     }
    // }

    //}

    return 0;
}
