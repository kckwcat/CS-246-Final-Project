module TextDisplay;
import Player;
import Board;
import Display;

void TextDisplay::render(const Board &board, const Player &player, bool lowercase) const {
        board.displayForViewer(player, lowercase);
}