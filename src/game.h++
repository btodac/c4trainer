#include <vector>
#include <string>
#include <unordered_map>

#include <src/player.h++>


struct GameState {
    std::unordered_map<std::string, int> scores;
    bool finished;

    GameState();
    GameState(std::unordered_map<std::string, int> scores, bool finished);
};

class Game {
    public:
        Game(/* args */);
        ~Game();

        void addPlayer(Player player);
        void start();
        void stop(Player player);
        void reset();

    protected:
        uint n_players;

        uint choose_random_player();
        std::vector<Player> players{};
};


