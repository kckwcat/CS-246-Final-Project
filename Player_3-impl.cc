module Player;
import <iostream>;
import <vector>;
import <memory>;
import <algorithm>;
import <string>;
import Link;
import Ability;
using namespace std;

Player::Player(int id): playerID{id} {}
      int Player::getPlayerID() const {
            return playerID;
      }
      string Player::getName() const { return "P" + to_string(playerID); }

      shared_ptr<Link> Player::getLinkByIdChar(char ch) {
                if (ch < 'a' || ch > 'z') return nullptr;
                int idx = ch - 'a';
                if (idx < 0 || idx >= (int)links.size()) return nullptr;
                return links[idx];
        }
        int Player::getAbilitySize() const{
            return abilities.size();
        }

/*        vector<unique_ptr<Ability>> Player::getAbilities(){
                return abilities;
        } */
       Ability* Player::extractAbility(int index) const{
            return abilities[index].get();
       }

    void Player::addDownloaded(shared_ptr<Link> L) {
        if (!L) return;
        if (L->isVirus()) downloadsVirus++; else downloadsData++;
        downloadedByMe.push_back(L);
    }
    void Player::addAgainstMe(shared_ptr<Link> L) {
        if (!L) return;
        downloadedAgainstMe.push_back(L);
    }
    void Player::removeLink(shared_ptr<Link> L) {
        links.erase(remove(links.begin(), links.end(), L), links.end());
    }

    void Player::listAbilities() const {
        cout << "Abilities for " << getName() << ":\n";
        for (int i=0;i<abilities.size();++i) {
            cout << i+1 << ": " << abilities[i]->get_name() << (abilities[i]->hasUsed() ? " (used)" : "") << "\n";
        }
    }

    bool Player::hasWon() const { return downloadsData >= 4; }
    bool Player::hasLost() const { return downloadsVirus >= 4; }
