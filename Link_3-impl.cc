module Link;
import <iostream>;
import <vector>;
import <string>;
using namespace std;


Link::Link(int s = 1, char t = 'D') : strength(s), type(t) {}

//Player* Link::getPlayer() const{ return owner;}
int Link::getPlayerID() const {return playerID;}
char Link::getType() const{return type;}

void Link::setType(char c){
        type = c;
}

bool Link::isVirus() const { return type == 'V'; }
    
bool Link::isData() const  { return type == 'D'; }

bool Link::isBoosted() const {return boosted; }
bool Link::isBreaching() const { return breached; }
    
        bool Link::isReinforced() const { return reinforced; }
    
        bool Link::isRejacked() const { return rejacked; }

    
        void Link::applyBoost() { boosted = true; }         // extra reach (next move)
    
        void Link::applyBreach() { breached = true; }       // extra reach this turn
    
        void Link::applyReinforce() { strength = 4; reinforced = true; } // cannot move this turn
    
        void Link::applyRejack() { rejacked = true; }       // flag reclaimed
    
        void Link::clearTurnFlags() { boosted = false; breached = false; reinforced = false; }

        void Link::resetBoost() { boosted = false;}
        void Link::resetBreach() {breached = false;}
        void Link::resetReinforce() {reinforced = false;}
        void Link::resetRejack() {rejacked = false;}

    
        string Link::shortLabel() const {
                string s;
                s += type;
                s += to_string(strength);
                return s;
        }

    // Battle result: returns true if this link (initiator) wins against other.
bool Link::battleVs(const Link& other, bool initiator) const {
        if (strength > other.strength) return true;
        if (strength < other.strength) return false;
        return initiator; // tie -> initiator wins
    }
