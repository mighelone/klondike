#include <iostream>
#include <string>
#include <deque>



#include "Card.hpp"
#include "Deck.hpp"

using namespace klondike;
using namespace std;


int main(int argc, char* argv[])
{
    Deck deck;
    Card c = deck.pop();
    std::cout << c << "\n";

    return 0;
}
