module PolarizeAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import Player;
using namespace std;


PolarizeAbility::PolarizeAbility(Player* p, vector<Player*> gamePlayers): Ability("Polarize"), owner(p), players(gamePlayers) {}
    //string PolarizeAbility::name() const { return "Polarize"; }
    bool PolarizeAbility::use(const vector<string>& args)  {
        if (!owner || args.empty()) { cout << "Polarize needs link id\n"; return false; }
        // find link anywhere
        for (auto &pl : players) {
            auto cand = pl->getLinkByIdChar(args[0][0]);
            if (cand) {
                if (cand->getType() == 'D') cand->setType('V'); else if (cand->getType() == 'V') cand->setType('D');
                cout << "Polarized\n";
                return true;
            }
        }
        cout << "Link not found\n"; return false;
    }
