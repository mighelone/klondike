#include <iostream>
#include "Card.hpp"
#include <string>
#include <map>

using namespace klondike;
using namespace std;

enum CV {
    Ace=1,
    Two=2,
    Three=3,
    Four=4,
    Five=5,
    Six=6,
    Seven=7,
    Jack=8,
    Queen=9,
    King=10
 };

int main(int argc, char* argv[])
{
    Card c(Card::Spades, Card::Ace);
    Card c1(0, 5);
    Card::Rank r = Card::Clubs;

    //std::cout << F(Card::Ace) << "\n";
    //std::cout <<  << "\n";
    // for(auto it: Card::RANK_NAMES)
    // {
    //     std::cout << it << "\n";
    // }
    // std::cout << Card::RANK_NAMES[Card::Hearts] << "\n";
    // std::cout << Card::RANK_NAMES[r] << "\n";
    //std::cout << Card::RANK_NAMES[0] << "\n";
    std::cout << c1 << "\n";

    return 0;
}
