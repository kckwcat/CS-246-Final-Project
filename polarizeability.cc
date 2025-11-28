export module PolarizeAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import Player;
using namespace std;


export struct PolarizeAbility : public Ability {
    Player *owner;
    vector<Player*> players;
    PolarizeAbility(Player* p, vector<Player*> gamePlayers);
    //name() returns Polarize
    //string name() const override;
    //use(game, args) returns true if a link has been polarized.
    bool use(const vector<string>& args) override;
};
