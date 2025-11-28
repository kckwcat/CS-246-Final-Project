export module display;
import player;
import Board;

export struct Display {
    virtual ~Display() = default;
    virtual void render(const Board &board, const Player &player, bool lowercase) const = 0;
};