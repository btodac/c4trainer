#include <connect4.h++>

MoveOutcome ConnectFourBoard::update(uint col, HoleState token) {
  // determine highest row in col
  uint row = 0;
  for (row; row < n_rows; row++) {
    uint index = row * n_cols + col;
    HoleState current_state = board[index];
    if (current_state == HoleState(free)) {
      current_state = token;
      if (has_connected_four(index, token)) return connect_four;
      return valid;
    }
  }
  return invalid;
};

bool has_connected_four(uint move, HoleState token) {
    //check if the token sits in a row with 3 neighbours of the same token
    //check the column
    // check the diagonals
    return false;
}

void ConnectFour::play() {
  GameState game_state = GameState();
  uint i = choose_random_player();

  for (;;) {
    Player player = players[i];
    HoleState token = HoleState(i + 1);
    uint move = player.move(game_state);
    MoveOutcome outcome = board.update(move, token);
    switch (outcome) {
      case valid:
        player.update_score(1);
        i = (i + 1) % n_players;
        break;
      case invalid:
        player.update_score(-1);
        break;
      case connect_four:
        player.update_score(2);
        stop(player);
        return;
    }
  }
};

void ConnectFour::stop(Player player) {};
void ConnectFour::reset() {};