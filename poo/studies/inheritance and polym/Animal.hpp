#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief superclasse Animal de um animal genérico
 * 
 */
class Animal {
  public:
    int age;
    string name;
    
    /**
     * @brief Construtor padrão da classe
     * 
     */
    Animal(); // construtor padrão (default)

    /**
     * @brief Construtor personalizado da classe
     * 
     * @param x idade do animal
     * @param str nome do animal
     */
    Animal(int x, string str); 

    /**
     * @brief função que retorna o que o animal está comendo
     * 
     * @return texto de o que está comendo 
     */
    virtual string eatFood();
};

#endif