module Game;

import <iostream>;
import <vector>;
import <memory>;
import Ability;
import Link;
import Player;
import Board;
import Display;
import GraphicDisplay;
using namespace std;

Game::Game(int nplayers) {
        for (int i=0;i<nplayers;++i) players.emplace_back(make_unique<Player>(i+1));
        textDisplay1 = make_unique<Display>();
        textDisplay2 = make_unique<Display>();
    }

    Player& Game::getCurrentPlayer() { return *players[currentPlayerIndex]; }
    Player& Game::otherPlayer() { return *players[(currentPlayerIndex+1) % players.size()]; }

    void Game::nextTurn() { currentPlayerIndex = (currentPlayerIndex + 1) % players.size(); }

    // display functions matching classmate names
    void Game::display_board() {
        cout << "======= Player 1 view =======\n";
        textDisplay1->render(board, *players[0], player2Lowercase ? false : false);
        cout << "======= Player 2 view =======\n";
        textDisplay2->render(board, *players[1], player2Lowercase);
    }

    void Game::display_board_graphics() {
        // For this assignment graphics is a stub: call graphics view for both players
        auto gdisp = make_unique<GraphicsDisplay>();
        gdisp->render(board, *players[0], false);
        gdisp->render(board, *players[1], player2Lowercase);
    }

    void Game::endGame() {
        // check players for win/loss and print messages
        if (players[0]->hasWon()) cout << "Player 1 has won\n";
        else if (players[0]->hasLost()) cout << "Player 1 has lost\n";
        else if (players[1]->hasWon()) cout << "Player 2 has won\n";
        else if (players[1]->hasLost()) cout << "Player 2 has lost\n";
        else cout << "Game ended (no winner detected)\n";
        finished = true;
    }

    // execute a move (char link id -> direction string)
    bool Game::executeMove(char linkId, const string &dirStr) {
        Player &p = getCurrentPlayer();
        auto link = p.getLinkByIdChar(linkId);
        if (!link) { cout << "Invalid link id\n"; return false; }

        Pos from;
        if (!board.findLinkPos(link, from)) { cout << "Link not on board\n"; return false; }

        int dr = 0, dc = 0;
        if (dirStr == "up") { dr = -1; dc = 0; }
        else if (dirStr == "down") { dr = 1; dc = 0; }
        else if (dirStr == "left") { dr = 0; dc = -1; }
        else if (dirStr == "right") { dr = 0; dc = 1; }
        else { cout << "Invalid direction\n"; return false; }

        Pos to = from;
        to.r += dr; to.c += dc;

        // boost: one extra cell
        if (link->isBoosted()) { to.r += dr; to.c += dc; link->resetBoost();}

        // breach: extra 2 cells
        if (link->isBreaching()) { to.r += 2*dr; to.c += 2*dc; link->resetBreach();}

        // reinforce prevents move this turn
        if (link->isReinforced()) {
            cout << "This link is reinforced and cannot move this turn.\n";
            link->resetReinforce(); // consumes the reinforcement
            return false;
        }

        // off-edge: allow moving off opponent start edge only
        bool offEdge = !board.inBounds(to);
        if (offEdge) {
            int pid = p.getPlayerID();
            if (pid == 1 && to.r >=board.getR()) {
                // player 1 moving off bottom: download
            } else if (pid == 2 && to.r < 0) {
                // player 2 moving off top: download
            } else {
                cout << "Cannot move off that edge\n"; return false;
            }
            board.clearPos(from);
            p.addDownloaded(link);
            p.removeLink(link);
            cout << p.getName() << " downloaded their own link by moving off opponent edge.\n";
            return true;
        }

        auto occ = board.get(to);
        if (!occ) {
            board.clearPos(from);
            board.place(link, to);
            cout << "Moved " << linkId << " to (" << to.r << "," << to.c << ")\n";
            return true;
        } else {
            if (occ->owner == &p) {
                cout << "Cannot move onto your own link\n";
                return false;
            }
            // battle
            bool initiatorWins = link->battleVs(*occ, true);
            Player *winner = initiatorWins ? dynamic_cast<Player *>(&p) : static_cast<Player *>(occ->owner);
            Player *loser  = initiatorWins ? occ->owner : &p;
            shared_ptr<Link> winnerLink = initiatorWins ? link : occ;
            shared_ptr<Link> loserLink  = initiatorWins ? occ : link;

            board.clearPos(from);
            board.clearPos(to);
            board.place(winnerLink, to);

            winner->addDownloaded(loserLink);
            loser->removeLink(loserLink);
            loser->addAgainstMe(loserLink);

            cout << winner->getName() << " wins battle and downloads opponent link.\n";
            return true;
        }
    }

    // use ability (1-based index)
    bool Game::useAbility(int index, const vector<string>& args) {
        Player &p = getCurrentPlayer();
        if (index < 1 || index > (int)p.abilities.size()) { cout << "Invalid ability index\n"; return false; }
        Ability* a = p.abilities[index-1].get();
        if (a->hasUsed()) { cout << "Ability already used\n"; return false; }
        //bool ok = a->use(*this, args);
        bool ok = a->use(args);
        if (ok) { a->markUsed(); cout << "Ability used: " << a->get_name() << "\n"; }
        else cout << "Ability use failed\n";
        return ok;
    }

    Player* Game::getPlayerById(int id) {
        for (auto &pl : players) if (pl->getPlayerID() == id) return pl.get();
        return nullptr;
    }

    void Game::checkWinConditions() {
        for (auto &pl : players) {
            if (pl->hasWon()) {
                cout << pl->getName() << " wins by downloading 4 data!\n";
                finished = true;
                return;
            } else if (pl->hasLost()) {
                cout << pl->getName() << " loses (downloaded 4 viruses)!\n";
                finished = true;
                return;
            }
        }
    }
