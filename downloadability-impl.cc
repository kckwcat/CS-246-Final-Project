import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Link;
import Game;
import player;
using namespace std;

DownloadAbility::DownloadAbility(Player* p=nullptr): Ability(p) {}
string DownloadAbility::name() const { return "Download"; }
    bool DownloadAbility::use(Game &game, const vector<string>& args) override {
        if (!owner || args.empty()) { cout << "Download requires target id\n"; return false; }
        // find target among other players
        shared_ptr<Link> target = nullptr; Player* targetOwner = nullptr;
        for (auto &pl : game.players) {
            if (pl.get() == owner) continue;
            auto cand = pl->getLinkByIdChar(args[0][0]);
            if (cand) { target = cand; targetOwner = pl.get(); break; }
        }
        if (!target) { cout << "Target not found\n"; return false; }
        Pos pos;
        if (game.board.findLinkPos(target, pos)) game.board.clearPos(pos);
        targetOwner->removeLink(target);
        owner->addDownloaded(target);
        targetOwner->addAgainstMe(target);
        return true;
    }
