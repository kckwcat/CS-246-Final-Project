export module Display;
import Player;
import Board;

export struct Display {
    virtual ~Display() = 0;
    virtual void render(const Board &board, const Player &player, bool lowercase) const = 0;
};
