export module boostAbility;
import <iostream>;
import <memory>;
import <vector>;
import <string>;
import Ability;
import Game;
import player;
export struct BoostAbility : public Ability {
    BoostAbility(Player* p=nullptr);
    string name() const override;
    bool use(Game &game, const vector<string>& args) override;
};
