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

    string getName();

    // getLinkByIdChar(char c): returns a link by it's ID
    shared_ptr<Link> getLinkByIdChar(char ch);

  // addDownloaded(shared_ptr<Link> L) adds enemy link to list of oppents links
    void addDownloaded(shared_ptr<Link> L);
  // addAgainstMe(shared_ptr<Link> L): Adds an enemy link to the player
    void addAgainstMe(shared_ptr<Link> L);
  //addAgainstMe(shared_ptr<Link> L): Removes a link from the player
    void removeLink(shared_ptr<Link> L);
  //listAbilities() lists a players abilites
    void listAbilities() const;
  //hasWon: returns true if a player has won
    bool hasWon() const;
   // hasLost(): returns true if a player has lost
    bool hasLost() const;
};
