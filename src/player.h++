#include <vector>
#include <string>

class Player
{
private:
    /* data */
public:
    Player(/* args */);
    ~Player();

    uint move(GameState state);
    void update_score(int delta);

    std::string name;
};


