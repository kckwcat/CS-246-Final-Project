#include "Board.h"
#include <iostream>
using namespace std;

void Board::displayForViewer(const Player &viewer, bool player2Lowercase) const {
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            Pos p(r, c);

            // Show firewall if present
            char fw = firewalls[r][c];
            if (fw != 0) {
                cout << fw;
                continue;
            }

            auto L = grid[r][c];
            if (!L) {
                cout << '.';
                continue;
            }

            // Viewer sees own links fully, opponent links only type (or lowercase if spectate)
            char disp = L->getSymbol();

            if (L->ownerID != viewer.getID()) {
                if (player2Lowercase)
                    disp = tolower(disp);
                else
                    disp = L->knownTo(viewer) ? disp : '?';
            }

            cout << disp;
        }
        cout << '\n';
    }
}
