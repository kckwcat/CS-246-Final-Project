export module RejackAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import player;


RejackAbility::RejackAbility(Player* p=nullptr): Ability(p) {}
    string RejackAbility::name() const { return "Rejack"; }
    bool RejackAbility::use(Game &game, const vector<string>& args) {
        if (!owner) return false;
        if (owner->downloadedAgainstMe.empty()) { cout << "No links to rejack\n"; return false; }
        auto reclaimed = owner->downloadedAgainstMe.back();
        owner->downloadedAgainstMe.pop_back();
        reclaimed->applyRejack();
        owner->links.push_back(reclaimed);
        // try to place reclaimed near player's side
        int rowbase = (owner->playerID == 1 ? 1 : Board::R - 2);
        bool placed = false;
        for (int c=0;c<Board::C && !placed;++c) {
            Pos p(rowbase, c);
            if (!game.board.get(p)) { game.board.place(reclaimed, p); placed = true; }
        }
        if (!placed) {
            for (int r=0;r<Board::R && !placed;++r) for (int c=0;c<Board::C && !placed;++c) {
                Pos p(r,c);
                if (!game.board.get(p)) { game.board.place(reclaimed, p); placed = true; }
            }
        }
        return true;
    }