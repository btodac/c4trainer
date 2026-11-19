#include <iostream>
#include <src/player.h++>
#include <src/connect4/connect4.h++>

int main() {
    ConnectFour game = ConnectFour();
    Player player1 = Player();
    Player player2 = Player();
    game.addPlayer(player1);
    game.addPlayer(player2);
    game.play();
    std::cout << "Hello, World!\n";
    return 0;
}