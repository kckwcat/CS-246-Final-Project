export module ScanAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import player;

export struct ScanAbility : public Ability {
    ScanAbility(Player* p=nullptr);
    string name() const override;
    bool use(Game &game, const vector<string>& args) override;
};
