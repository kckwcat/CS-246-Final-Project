export module boostAbility;
import <iostream>;
import <memory>;
import <vector>;
import <string>;
import Ability;
import Player;
using namespace std;
export struct BoostAbility : public Ability {
    Player* owner;
    BoostAbility(Player* p=nullptr);
    //string get_name() const;
    bool use(const vector<string>& args) override;
};
