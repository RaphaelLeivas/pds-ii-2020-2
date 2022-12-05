#include <stdio.h>
#include <iostream>
#include <cmath>

#include "Animal.hpp"
#include "Dog.hpp"

using namespace std;

int main(void) {
    Animal* a1 = new Animal(10, "Bob Esponja");
    Dog* d1 = new Dog(10, "Rufus", "Raul");
    Animal* a2 = new Dog();

    cout << a1->eatFood() << endl;
    cout << a2->eatFood() << endl;
 
    return 0;
}