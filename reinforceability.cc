export module ReinforceAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import player;



struct ReinforceAbility : public Ability {
    ReinforceAbility(Player* p=nullptr);
    string name() const override;
    bool use(Game &game, const vector<string>& args) override;
};