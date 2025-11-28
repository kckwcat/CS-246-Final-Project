export module display;
import <iostream>;
import player;
import Board;

void GraphicsDisplay::render(const Board &board, const Player &player, bool lowercase) const {
        cout << "[Graphics stub] rendering for " << player.getName() << "\n";
        board.displayForViewer(player, lowercase);
}