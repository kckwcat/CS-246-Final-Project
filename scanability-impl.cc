module ScanAbility;
import <iostream>;
import <memory>;
import <string>;
import <vector>;
import Ability;
import Game;
import Link;
import Player;

ScanAbility::ScanAbility(Player* p=nullptr): Ability(p) {}
    string ScanAbility::name() const  { return "Scan"; }
    bool ScanAbility::use(Game &game, const vector<string>& args){
        if (!owner || args.empty()) { cout << "Scan needs arg\n"; return false; }
        char ch = args[0][0];
        for (auto &pl : game.players) {
            auto cand = pl->getLinkByIdChar(ch);
            if (cand) {
                cout << "Scan result: Owner=" << pl->getName() << " Type=" << (cand->isVirus() ? "Virus" : "Data") << " Str=" << cand->strength << "\n";
                return true;
            }
        }
        // or parse as pos
        auto comma = args[0].find(',');
        if (comma != string::npos) {
            int r = stoi(args[0].substr(0,comma));
            int c = stoi(args[0].substr(comma+1));
            Pos p(r,c);
            if (!game.board.inBounds(p)) { cout << "Invalid pos\n"; return false; }
            auto L = game.board.get(p);
            if (!L) { cout << "Empty\n"; return true; }
            cout << "Scan at " << r << "," << c << ": Type=" << (L->isVirus() ? "Virus" : "Data") << " Str=" << L->strength << "\n";
            return true;
        }
        cout << "Scan: nothing found\n";
        return false;
    }
