#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Estudante.hpp"

using namespace std;

int main() {
    Estudante alunos[10];
    float rsg[10];
    
    for(int i = 0; i < 10; ++i) {
        cin >> alunos[i].matricula >> alunos[i].nome;
        for(int j = 0; j < 5; ++j) {
            cin >> alunos[i].notas[j];
        }
        rsg[i] = alunos[i].calcularRSG();
    }

    sort(begin(rsg), end(rsg));
    reverse(begin(rsg), end(rsg));

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(alunos[j].calcularRSG() == rsg[i]){
                cout << setprecision(2) << fixed << alunos[j].matricula << " " 
                << alunos[j].nome << " " << alunos[j].calcularRSG() << endl;

                alunos[j].notas[0] = 0; // exclui ele apos ja ser selecionado
                break;
            }
        }
    }

    return 0;
}