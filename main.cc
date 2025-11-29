import <iostream>;
import <string>;
import commandParser;
import Game;
using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Game game(2);
    //seedDefaultGame(game);

    // optional graphics flag not used beyond stub
    for (int i=1;i<argc;i++) if (string(argv[i]) == "-nolower") game.setPlayer2LowerCase(false);

    CommandParser cp(game);
    cp.runInteractive();

    return 0;
}