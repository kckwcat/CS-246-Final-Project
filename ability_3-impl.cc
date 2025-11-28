module Ability;
import <iostream>;
import <string>;
using namespace std;

Ability::Ability(string name):
    used(false), name{name} {}

bool Ability::hasUsed() const{
    return used;
}

void Ability::markUsed(){
    used = true;
}

string Ability::get_name() const {
    return name;
}
