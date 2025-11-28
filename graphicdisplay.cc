export module GraphicDisplay;
import <iostream>;
import Player;
import Board;
import Display;
export struct GraphicsDisplay : public Display {
    // render(board, player, lowercase) displays graphic version of the board
    void render(const Board &board, const Player &player, bool lowercase) const override;
};
