export module display;
import player;
import Board;

struct TextDisplay : public Display {
    void render(const Board &board, const Player &player, bool lowercase) const override;
};