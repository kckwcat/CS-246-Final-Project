module PolarizeAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import player;


PolarizeAbility::PolarizeAbility(Player* p=nullptr): Ability(p) {}
    string PolarizeAbility::name() const { return "Polarize"; }
    bool PolarizeAbility::use(Game &game, const vector<string>& args)  {
        if (!owner || args.empty()) { cout << "Polarize needs link id\n"; return false; }
        // find link anywhere
        for (auto &pl : game.players) {
            auto cand = pl->getLinkByIdChar(args[0][0]);
            if (cand) {
                if (cand->type == TYPE_DATA) cand->type = TYPE_VIRUS; else if (cand->type == TYPE_VIRUS) cand->type = TYPE_DATA;
                cout << "Polarized\n";
                return true;
            }
        }
        cout << "Link not found\n"; return false;
    }