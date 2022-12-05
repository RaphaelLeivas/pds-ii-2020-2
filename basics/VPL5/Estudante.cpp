#include "Estudante.hpp"

float Estudante::calcularRSG() {
    float rsg = 0;
    
    for(int i = 0; i < 5; ++i) {
        rsg += (this->notas[i])/(float)5;
    }

    return rsg;
}