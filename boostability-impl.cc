module boostAbility;
import <iostream>;
import <memory>;
import <vector>;
import <string>;
import Ability;
import Player;
using namespace std;

BoostAbility::BoostAbility(Player* p): Ability("LinkBoost"), owner(p) {}

 //string BoostAbility::name() const { return "LinkBoost"; }

    bool BoostAbility::use(const vector<string>& args){
        if (!owner || args.empty()) { cout << "Boost requires link id\n"; return false; }
        auto L = owner->getLinkByIdChar(args[0][0]);
        if (!L) { cout << "Link not found\n"; return false; }
        L->applyBoost();
        return true;
    }
