#include <iostream>
#include <string>
#include <deque>



#include "Card.hpp"
#include "Deck.hpp"
#include "Stack.hpp"

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

    // test simple
    // stack.push_hidden(Card(Card::Diamonds, Card::King));
    stack.turn_card();
    //
    // std::cout << "Last visible: " << stack.last_visible();
    // if (stack.last_visible().is_red())
    // {
    //     cout << " is red" << endl;
    // }
    //
    // Card card(Card::Spades, Card::Queen);
    //
    // if (stack.can_add_card(card))
    // {
    //     cout << "Add " << card << " to the stack, with last: " << stack.last_visible() << endl;
    //     stack.add_card_visible(card);
    // }

    //std::cout << "Now last visible is " << stack.last_visible() << "\n";

    cout << endl;
    while (!deck.empty())
    {
        //cout << endl << endl << endl << endl << endl << endl << endl << endl;
        for (int i=0; i<2; i++)
            cout << endl;
        cout << "Last visible card is " << stack.last_visible() << endl;
        Card card = deck.pop();
        cout << "New card is " << card <<endl;
        if (stack.can_add_card(card))
        {
            cout << "Add to the stack" << endl;
            stack.add_card_visible(card);
        }
    }

    //}

    return 0;
}
