module boostAbility;
import <iostream>;
import <memory>;
import <vector>;
import <string>;
import Ability;
import Game;
import player;

BoostAbility::BoostAbility(Player* p=nullptr): Ability(p) {}

 string BoostAbility::name() const { return "LinkBoost"; }

    bool BoostAbility::use(Game &game, const vector<string>& args){
        if (!owner || args.empty()) { cout << "Boost requires link id\n"; return false; }
        auto L = owner->getLinkByIdChar(args[0][0]);
        if (!L) { cout << "Link not found\n"; return false; }
        L->applyBoost();
        return true;
    }
