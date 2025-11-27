module Ability;
import <iostream>;
import <string>;
import player;

Ability::Ability(Player* p=nullptr):
    used(false), owner(p) {}

Ability::~Ability(){
    
}

bool Ability::hasUsed() const{
    return used;
}

void Ability::markUsed(){
    used = true;
}

void Ability::setOwner(Player* p){
    owner = p;
}

Player* Ability::getOwner() const{
    return owner;
}
