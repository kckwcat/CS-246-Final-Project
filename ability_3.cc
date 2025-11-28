export module Ability;
import <iostream>;
import <string>;
import <vector>;
using namespace std;


export class Ability {
    protected:
        string name;
        bool used = false;
    public:
        //ctor
        Ability(string name);

        //hasUsed(); returns true if ability has been used
        bool hasUsed() const;

        //markUsed(); marks an ability as used
        void markUsed();

        // string get_name(): returns an abilites name
        string get_name() const;

        //use(const vector<string> &args) applies an ability in the match
        virtual bool use(const vector<string> &args) = 0;
};
