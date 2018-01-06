#include <iostream>
#include "Card.hpp"
#include <string>
#include <map>

using namespace klondike;
using namespace std;


int main(int argc, char* argv[])
{
    Card c(Card::Spades, Card::Ace);
    Card c1(3, 1); // Ace of spades again

    // should print Ace of Spades
    std::cout << c << "\n";
    std::cout << c1 << "\n";

    return 0;
}
