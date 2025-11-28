module BreachAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Link;
import Player;
using namespace std;

 BreachAbility::BreachAbility(Player* p): Ability("Breach"),  owner(p){}
    //string BreachAbility::name() const { return "Breach"; }
    bool BreachAbility::use(const vector<string>& args) {
        if (!owner || args.empty()) { cout << "Breach needs link id\n"; return false; }
        auto L = owner->getLinkByIdChar(args[0][0]);
        if (!L) { cout << "Link not found\n"; return false; }
        L->applyBreach();
        return true;
    }
