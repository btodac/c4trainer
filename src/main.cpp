#include <iostream>
#include <src/player.h++>
#include <src/connect4/connect4.h++>

int main() {
    ConnectFour* game = new ConnectFour();
    Player* player1 = new Player();
    Player* player2 = new Player();
    game->addPlayer(*player1);
    game->addPlayer(*player2);
    game->play();
    std::cout << "Hello, World!\n";
    return 0;
}