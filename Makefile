all:
        @g++-14 -std=c++20 -fmodules-ts -c -x c++-system-header iostream vector memory sstream algorithm string 
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c link.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c link-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c ability.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c ability-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c board.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c board-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c player.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c player-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c display.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c game.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c game-impl.cc
