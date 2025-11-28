export module Link;
import <iostream>;
import <string>;
using namespace std;


export class Link {
    // Note: public members here for simplicity; could be private with getters/setters.
    int strength;
    char type;          // 'D' or 'V' or '?'
    bool boosted = false;
    bool breached = false;
    bool reinforced = false;
    bool rejacked = false;
    int playerID;

        public:

                Link(int strength, char type);
                int getPlayerID() const;
                char getType() const;
                void setType(char c);

                // Type checks
                bool isVirus() const;
                bool isData() const;

                //Ability usage checks
                bool isBoosted() const;
                bool isBreaching() const;
                bool isReinforced() const;
                bool isRejacked() const;

                // ability applications;
                void applyBoost();
                void applyBreach();
                void applyReinforce();
                void applyRejack();
                void clearTurnFlags();
                void resetBoost();
                void resetBreach();
                void resetReinforce();
                void resetRejack();


                // shortLabel(): returns link in the form of 'V#' or 'D#'
                string shortLabel() const;

                // Battle result: returns true if this link (initiator) wins against other. Else False
                bool battleVs(const Link& other, bool initiator) const;
};
