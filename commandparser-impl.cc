#include <bits/stdc++.h>
module commandParser;
import <string>;
import <vector>;
import <memory>;
import <iostream>;
import <sstream>;
import <algorithm>;
import Game;
import Player;
using namespace std;



static vector<string> CommandParser::tokenize(const string &s) {
        vector<string> out; string tok; istringstream iss(s);
        while (iss >> tok) out.push_back(tok);
        return out;
    }

    void CommandParser::runInteractive() {
        cout << "RAIInet running. Type 'help' for commands.\n";
        string line;
        while (!quitFlag && !game.finished) {
            cout << game.getCurrentPlayer().getName() << "> ";
            if (!getline(cin, line)) break;
            if (line.empty()) continue;
            processLine(line);
            game.checkWinConditions();
            if (!game.finished) game.nextTurn();
        }
        cout << "Goodbye.\n";
    }

    void CommandParser::runSequence(const string &filename) {
        ifstream ifs(filename);
        if (!ifs) { cout << "Cannot open sequence\n"; return; }
        string line;
        while (getline(ifs, line) && !quitFlag && !game.finished) {
            if (line.empty()) continue;
            cout << "[seq] " << line << "\n";
            processLine(line);
            game.checkWinConditions();
            if (!game.finished) game.nextTurn();
        }
    }

    void CommandParser::processLine(const string &line) {
        auto toks = tokenize(line);
        if (toks.empty()) return;
        string cmd = toks[0];
        if (cmd == "help") {
            cout << "Commands: board | move <link> <dir> | abilities | ability <N> [args] | sequence <file> | quit\n";
            return;
        }
        if (cmd == "quit") { quitFlag = true; game.endGame(); return; }
        if (cmd == "board") { game.display_board(); return; }
        if (cmd == "move") {
            if (toks.size() < 3) { cout << "Usage: move <link> <up|down|left|right>\n"; return; }
            char id = toks[1][0];
            game.executeMove(id, toks[2]);
            return;
        }
        if (cmd == "abilities") { game.getCurrentPlayer().listAbilities(); return; }
        if (cmd == "ability") {
            if (toks.size() < 2) { cout << "usage: ability <N> [args]\n"; return; }
            int idx = stoi(toks[1]);
            vector<string> args;
            for (size_t i=2;i<toks.size();++i) args.push_back(toks[i]);
            game.useAbility(idx, args);
            return;
        }
        if (cmd == "sequence") {
            if (toks.size() < 2) { cout << "usage: sequence <file>\n"; return; }
            runSequence(toks[1]); return;
        }
        cout << "Unknown command\n";
    }
