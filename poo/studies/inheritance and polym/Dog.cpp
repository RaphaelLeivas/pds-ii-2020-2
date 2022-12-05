#include "Dog.hpp"

Dog::Dog() = default;

Dog::Dog(int x, string str, string own) {
    this->age = x;
    this->name = str;
    this->owner = own;
}

string Dog::eatFood() {
    return "I am a Dog eating fresh meat!";
}