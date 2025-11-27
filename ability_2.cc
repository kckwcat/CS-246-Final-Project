export module Ability;
import <iostream>;
import <string>;
import <vector>;
import Player;
import Game;


export class Ability {
    protected:
        string name;
        bool used = false;
    public:
        //ctor
        Ability(string name);

        //dtor
        virtual ~Ability() = default;
        //hasUsed(); returns true if ability has been used
        bool hasUsed() const;

        //markUsed(); marks an ability as used
        void markUsed();

        // string name(): returns an abilites name
        string name() const;

        //use(Game &game, const vector<string> &args) applies an ability in the match
        virtual bool use(Game &game, const vector<string> &args) = 0;
};
