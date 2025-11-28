module Board;
import <iostream>;
import <vector>;
import <memory>;
import <string>;
import Link;
using namespace std;

Board::Board() {
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            grid[r][c] = nullptr;
            firewalls[r][c] = 0;
        }
}

int Board::getR() const{
    return R;
}

int Board::getC() const{
    return C;
}

bool Board::inBounds(const Pos &p) const {
    return p.r >= 0 && p.r < R && p.c >= 0 && p.c < C;
}

std::shared_ptr<Link> Board::get(const Pos &p) const {
    if (!inBounds(p)) return nullptr;
    return grid[p.r][p.c];
}

void Board::place(const std::shared_ptr<Link>& L, const Pos &p) {
    if (!inBounds(p)) return;
    grid[p.r][p.c] = L;
}

void Board::clearPos(const Pos &p) {
    if (!inBounds(p)) return;
    grid[p.r][p.c] = nullptr;
}

void Board::setFirewall(const Pos &p, char ch) {
    if (!inBounds(p)) return;
    firewalls[p.r][p.c] = ch;
}

char Board::firewallAt(const Pos &p) const {
    if (!inBounds(p)) return 0;
    return firewalls[p.r][p.c];
}

void Board::removeFirewall(const Pos &p) {
    if (!inBounds(p)) return;
    firewalls[p.r][p.c] = 0;
}

bool Board::isServer(const Pos &p, int playerID) const {
    if (playerID == 1) return p.r == 0 && (p.c == 3 || p.c == 4);
    if (playerID == 2) return p.r == R - 1 && (p.c == 3 || p.c == 4);
    return false;
}

bool Board::findLinkPos(const std::shared_ptr<Link>& L, Pos &out) const {
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (grid[r][c] == L) { out = Pos(r, c); return true; }
    return false;
}

bool Board::findLinkPosRaw(const Link* raw, Pos &out) const {
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (grid[r][c] && grid[r][c].get() == raw) { out = Pos(r, c); return true; }
    return false;
}

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
            char disp = L->getType();

            if (L->getPlayerID() != viewer.getPlayerID()) {
                if (player2Lowercase)
                    disp = tolower(disp);
                else
		        disp = '?';
            }

            cout << disp;
        }
        cout << '\n';
    }
}
