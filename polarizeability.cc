export module PolarizeAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import player;

export struct PolarizeAbility : public Ability {
    PolarizeAbility(Player* p=nullptr);
    string name() const override;
    bool use(Game &game, const vector<string>& args) override;
};