export module ScanAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import player;

 BreachAbility::BreachAbility(Player* p=nullptr): Ability(p) {}
    string BreachAbility::name() const { return "Breach"; }
    bool BreachAbility::use(Game &game, const vector<string>& args) {
        if (!owner || args.empty()) { cout << "Breach needs link id\n"; return false; }
        auto L = owner->getLinkByIdChar(args[0][0]);
        if (!L) { cout << "Link not found\n"; return false; }
        L->applyBreach();
        return true;
    }