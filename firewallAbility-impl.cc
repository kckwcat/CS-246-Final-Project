module FirewallAbility;
import <iostream>;
import <string>;
import <vector>;
import Ability;
import Game;
import player;
using namespace std;
FirewallAbility::FirewallAbility(Player* p=nullptr): Ability(p) {}
string FirewallAbility::name() const { return "Firewall"; }
    bool FirewallAbility::use(Game &game, const vector<string>& args) {
        if (!owner || args.empty()) { cout << "Firewall requires r,c\n"; return false; }
        string s = args[0];
        auto comma = s.find(',');
        if (comma==string::npos) { cout << "Invalid pos\n"; return false; }
        int r = stoi(s.substr(0,comma)), c = stoi(s.substr(comma+1));
        Pos ppos(r,c);
        if (!game.board.inBounds(ppos)) { cout << "pos out of bounds\n"; return false; }
        if (game.board.get(ppos)) { cout << "pos not empty\n"; return false; }
        char sym = (owner->playerID==1 ? 'm' : 'w');
        game.board.setFirewall(ppos, sym);
        return true;
    }
