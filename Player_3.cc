export module Player;
import <iostream>;
import <vector>;
import<memory>;
import<string>;
import Link;
import Ability;
using namespace std;

export class Player {
    int playerID;
    vector<shared_ptr<Link>> links;           // active links owned by player
    vector<unique_ptr<Ability>> abilities;    // ability objects owned
    vector<shared_ptr<Link>> downloadedByMe;
    vector<shared_ptr<Link>> downloadedAgainstMe;
    int downloadsData = 0;
    int downloadsVirus = 0;

    public:

    Player(int id=0);
    int getPlayerID() const;
    string getName() const;
    
    // getLinkByIdChar(char c): returns a link by it's ID
    shared_ptr<Link> getLinkByIdChar(char ch);
    /*vector<unique_ptr<Ability>> getAbilities(); */
    int getAbilitySize() const;

    Ability* extractAbility(int index) const;

    void addDownloaded(shared_ptr<Link> L);
    void addAgainstMe(shared_ptr<Link> L);

    void removeLink(shared_ptr<Link> L);

    void listAbilities() const;

    bool hasWon() const;
    bool hasLost() const;
};
