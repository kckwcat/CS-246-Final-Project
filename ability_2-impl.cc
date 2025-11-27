module Ability;
import <iostream>;
import <string>;
import player;

Ability::Ability(string name):
    used(false), name{name} {}

Ability::~Ability(){

}

bool Ability::hasUsed() const{
    return used;
}

void Ability::markUsed(){
    used = true;
}

string Ability::name() const {
        return name;
}
