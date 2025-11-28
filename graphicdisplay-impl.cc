module GraphicDisplay;
import <iostream>;
import Player;
import Board;
import Display;
using namespace std;

void GraphicsDisplay::render(const Board &board, const Player &player, bool lowercase) const {
        cout << "[Graphics stub] rendering for " << player.getName() << "\n";
        board.displayForViewer(player, lowercase);
}