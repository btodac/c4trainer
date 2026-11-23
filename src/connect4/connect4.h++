#include <src/game.h++>

enum HoleState {
    free, player_1, player_2
};


enum MoveOutcome {
    valid, invalid, connect_four
};


class ConnectFourBoard {
    public:
        ConnectFourBoard();
        ConnectFourBoard(uint n_rows, uint n_cols) : n_rows(n_rows), n_cols(n_cols) {
            board = std::vector<HoleState>{n_cols * n_rows, HoleState(free)};
        };

        void draw();
        MoveOutcome update(uint col, HoleState state);

    private:
        std::vector<HoleState> board{6 * 7, HoleState(free)};
        uint n_rows{7};
        uint n_cols{6};

        bool has_connected_four(uint move, HoleState token);
};


class ConnectFour : public Game {
    
    protected:
        uint n_players = 2;

    private:
        ConnectFourBoard board{};
        bool has_connected_four(uint move, HoleState token);

    public:
        void play();
        void stop(Player player);
        void reset();
};