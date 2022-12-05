// aqui vem a definicao DOS METODOS da classe, com a logica suas funcoes internas
// use notacao tipoStruct::funcaoInterna 

#include "Circunferencia.hpp"

Circunferencia::Circunferencia(float x, float y, float r) {
    this->xc = x;
    this->yc = y;
    this->raio = r;
}

float Circunferencia::calcularArea() {
    return PI * pow(this->raio, 2);
}

bool Circunferencia::possuiIntersecao(Circunferencia* c) {
    float d = sqrt(pow(this->xc - c->xc, 2) + pow(this->yc - c->yc, 2));
    float r1 = this->raio, r2 = c->raio;

    if(d == 0 and r1 == r2) return true; // iguais
    if(d <= r1 + r2) return true; //  tangentes externas ou secantes
    if(r1 >= r2 and d == r1 - r2) return true; // tangentes internas 
    if(r2 >= r1 and d == r2 - r1) return true; // tangentes internas
    
    return false;
}
