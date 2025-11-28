module ReinforceAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Link;
import Player;
using namespace std;

ReinforceAbility::ReinforceAbility(Player* p): Ability("Reinforce"),  owner(p) {}
    //string ReinforceAbility::name() const { return "Reinforce"; }
    bool ReinforceAbility::use(const vector<string>& args) {
        if (!owner || args.empty()) { cout << "Reinforce needs link id\n"; return false; }
        auto L = owner->getLinkByIdChar(args[0][0]);
        if (!L) { cout << "Link not found\n"; return false; }
        L->applyReinforce();
        return true;
    }
