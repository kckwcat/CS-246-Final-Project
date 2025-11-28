#include "Board.h"

Board::Board() {
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            grid[r][c] = nullptr;
            firewalls[r][c] = 0;
        }
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
