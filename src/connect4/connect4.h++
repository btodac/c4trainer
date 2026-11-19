#include <src/game.h++>


class ConnectFour : public Game {
    
    protected:
        uint n_players = 2;

    private:    
        bool is_valid_move(GameState state,uint move);
        void update_board(uint player, uint move);
        bool has_connected_four(GameState state);

    public:
        void play();
        void stop(Player player);
        void reset();
};