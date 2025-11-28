export module BreachAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Link;
import Player;
using namespace std;


export struct BreachAbility : public Ability {
    Player *owner;
    BreachAbility(Player* p=nullptr);
    //string name() const override;
    bool use(const vector<string>& args) override;
};
