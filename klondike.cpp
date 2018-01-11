
#include "Game.hpp"

using namespace klondike;

int main(int argc, char* argv[])
{

    Game game;
    while (true){
        game.print();
        game.print_prompt();
        game.prompt();
    }
    return 0;
}
