export module commandParser;
import <string>;
import <vector>;
import <memory>;
import <iostream>;
import <fstream>;
import <sstream>;
import <algorithm>;
import Game;
import Player;
using namespace std;
/* ------------------------
   CommandParser
   ------------------------ */
export struct CommandParser {
    Game &game;
    bool quitFlag = false;
    CommandParser(Game &g): game(g) {}

    //tokenize(s) inserts a token into the list of token.
    static vector<string> tokenize(const string &s);

    //runInteractive() setups the flow of the game
    void runInteractive();

    //runSequence(filename) processes the sequence inside the filename
    void runSequence(const string &filename);
    //processLine(line) acts as a controller for the game 
    void processLine(const string &line);
};
