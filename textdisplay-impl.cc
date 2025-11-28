export module display;
import player;
import Board;

void TextDisplay::render(const Board &board, const Player &player, bool lowercase) const {
        board.displayForViewer(player, lowercase);
}