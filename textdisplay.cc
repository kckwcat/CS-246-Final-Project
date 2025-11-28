export module TextDisplay;
import Player;
import Board;
import Display;

// render(board, player, lowercase) displays graphic version of the board
export struct TextDisplay : public Display {
    //render(board, player, lowercase) produces text version of the board display
    void render(const Board &board, const Player &player, bool lowercase) const override;
};