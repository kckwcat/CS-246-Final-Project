export module display;
import <iostream>;
import player;
import Board;
export struct GraphicsDisplay : public Display {
    void render(const Board &board, const Player &player, bool lowercase) const override;
};
