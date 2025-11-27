export module Ability;
import <iostream>;
import <string>;
import <vector>;
import player;


export struct Ability {
    protected:
        bool used = false;
        Player* owner = nullptr;
    public:
        Ability(Player* p=nullptr);
        virtual ~Ability() = default;
        bool hasUsed() const;
        void markUsed();
        void setOwner(Player* p);
        Player* getOwner() const;
        virtual string name() const = 0;
        virtual bool use(Game &game, const vector<string> &args) = 0;
};
