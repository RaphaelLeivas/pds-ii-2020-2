// .hpp contem somente os defines, headers de bibliotecas usadas, declaracao da struct e de suas variaves
// e funcoes internas

// includes
#include <cmath>

// defines
#define PI  3.14


struct Circunferencia {
    float xc;
    float yc;
    float raio;

    Circunferencia(float x, float y, float r); // metodo construtor da struct, quem cria ela 
    float calcularArea(); // acha a area da propria struct que chamou
    bool possuiIntersecao(Circunferencia* c); // ve se tem intersecao entre a circunferencia da chamada e do argumento
};