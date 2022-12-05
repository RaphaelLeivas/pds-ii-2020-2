#include "Animal.hpp"

Animal::Animal() = default;

Animal::Animal(int x, string str) {
    this->age = x;
    this->name = str;
}

string Animal::eatFood() {
    return "I am an animal eating generic food.";
}