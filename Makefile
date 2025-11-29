all:
        @g++-14 -std=c++20 -fmodules-ts -c -x c++-system-header iostream fstream vector memory sstream algorithm string 
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Link_3.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Link_3-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c ability_3.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c ability_3-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Board_3.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Board_3-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Player_3.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Player_3-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c display_3.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c display-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Game_3.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c Game_3-impl.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c commandparser.cc
        @g++-14 -std=c++20 -fmodules-ts -Wall -g -c commandparser-impl.cc

