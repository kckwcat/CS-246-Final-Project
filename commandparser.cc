import <string>;
import <vector>;
import <memory>;
import <algorithm>;
import Game;
using namespace std;
class commandParser{
    std::unique_ptr<Game> game;
    public:
	commandParser(){
		game = make_unique<Game>();
	}
    void abilitySequence(){
	game->getCurrentPlayer().playAbility();
    }
    void run(){
        game->start();
    }
    void execute(string cmd){
        game->getCurrentPlayer();
        game->nextTurn();
    }
    void quit(){
        game->endGame();
    }
}
