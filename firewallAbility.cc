import <iostream>;
import <string>;
import <vector>;
import Ability;
import Game;
import player;
export struct FirewallAbility : public Ability {
    FirewallAbility(Player* p=nullptr);
    string name() const override;
    bool use(Game &game, const vector<string>& args) override;
};
