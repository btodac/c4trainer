#include <connect4.h++>

void ConnectFour::play() {
    GameState game_state = GameState();
    uint i = choose_random_player();

    for (;;) {
        Player player = players[i];
        uint move = player.move(game_state);
        if (is_valid_move(game_state, move)) {
            player.update_score(1);
            update_board(i, move);
            if (has_connected_four(game_state)) {
                player.update_score(2);
                stop(player);
                break;
            } else {
                i = (i + 1) % n_players;
            }
        } else {
            player.update_score(-1);
        }

    }
};

bool ConnectFour::is_valid_move(GameState state, uint move) {};
void ConnectFour::update_board(uint player, uint move) {};
bool ConnectFour::has_connected_four(GameState state) {return true;};


void ConnectFour::stop(Player player) {};
void ConnectFour::reset() {};