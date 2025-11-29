CXX =  g++-14.2.0 -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header 
SOURCES = Link_3.cc ability_3.cc Board_3.cc Player_3.cc display_3.cc Game_3.cc commandparser.cc Link_3-impl.cc ability_3-impl.cc Board_3-impl.cc Player_3-impl.cc display_3-impl.cc Game_3-impl.cc commandparser-impl.cc
HEADERS = iostream fstream vector memory sstream algorithm string 
EXEC = RAIInet

$(EXEC): $(SOURCES)
        $(CXX) $(HEADERFLAGS) $(HEADERS)
        $(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)

