export module Game;
import <iostream>;
import <vector>;
import <memory>;
import <string>;
import Ability;
import Link;
import Player;
import Board;
import Display;
using namespace std;

export class Game {
    Board board;
    vector<unique_ptr<Player>> players;
    int currentPlayerIndex = 0;
    unique_ptr<Display> textDisplay1;
    unique_ptr<Display> textDisplay2;
    bool finished = false;
    bool player2Lowercase = true; // user preference for display

        public:

                Game(int nplayers=2);

                Player& getCurrentPlayer();
                Player& otherPlayer();
                void nextTurn();
                void display_board();
                void display_board_graphics();
                void endGame();
                bool executeMove(char linkId, const string &dirStr);
                bool useAbility(int index, const vector<string>& args);
                Player* getPlayerById(int id);
                void checkWinConditions();


            
};
