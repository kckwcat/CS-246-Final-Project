module ReinforceAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import Player;

ReinforceAbility::ReinforceAbility(Player* p=nullptr): Ability(p) {}
    string ReinforceAbility::name() const { return "Reinforce"; }
    bool ReinforceAbility::use(Game &game, const vector<string>& args) {
        if (!owner || args.empty()) { cout << "Reinforce needs link id\n"; return false; }
        auto L = owner->getLinkByIdChar(args[0][0]);
        if (!L) { cout << "Link not found\n"; return false; }
        L->applyReinforce();
        return true;
    }
