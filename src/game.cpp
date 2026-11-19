#include <src/game.h++>
#include <random>

unsigned bounded_rand(unsigned range)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, range);

    return dist(rng) - 1;
}



GameState::GameState() {
    this->finished = false;
    this->scores = std::unordered_map<std::string, int>();
};


GameState::GameState(
    std::unordered_map<std::string, int> scores,
    bool finished
) {
    this->scores = scores;
    this->finished = finished;
}

Game::Game(/* args */)
{
}

Game::~Game()
{
}

void Game::addPlayer(Player player) {
    if (players.size() < n_players)
        players.push_back(player);
}

uint Game::choose_random_player() {
    return bounded_rand(players.size());
}

void Game::start() {}
void Game::stop(Player player) {}

void Game::reset() {}