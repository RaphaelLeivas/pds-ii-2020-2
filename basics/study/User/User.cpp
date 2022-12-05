#include "User.hpp"

User::User(int x, string str) { // construtor: sem retorno especificado
    this -> age = x;
    this -> name = str;
}

string User::getName() {
    return this->name;
}

bool User::isTeenager() {
    if(this->age >= 10 and this->age <= 19) return true;
    else return false;
}