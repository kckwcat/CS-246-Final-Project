export module ReinforceAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Link;
import Player;
using namespace std;



export struct ReinforceAbility : public Ability {
    Player *owner;
    ReinforceAbility(Player* p=nullptr);
    //name() returns "Reinforce"
    //string name() const override;
    //use(args) returns true if reinforcement has a link
    bool use(const vector<string>& args) override;
};
