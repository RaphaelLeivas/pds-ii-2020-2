#ifndef DOG_H
#define DOG_H

#include <string>
#include "Animal.hpp"

using namespace std;

/**
 * @brief subclasse Dog da superclasse Animal
 * 
 */
class Dog : public Animal {
  public:
    string owner;

    /**
     * @brief Construtor padrão da classe Dog
     * 
     */
    Dog();

    /**
     * @brief Construtor personalizado da classe Dog
     * 
     * @param x idada
     * @param str nome
     * @param own nome do dono
     */
    Dog(int x, string str, string own);

    /**
     * @brief função que retorna o que o cachorro está comendo
     * 
     * @return texto de o que está comendo 
     */
    virtual string eatFood();
};

#endif