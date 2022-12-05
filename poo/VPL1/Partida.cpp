#include "Partida.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"

#include <iostream>
#include<bits/stdc++.h>

Partida::Partida(int num_jogadores) { // construtor
    this->_num_jogadores = num_jogadores;
}

// implementar destructor

void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe) {
    // cria e configura a carta dele
    Carta* p_card = new Carta(numero_pontos_carta, naipe);
    Carta card = *p_card;

    // agora verifica se jogador já existe para saber se deve add
    // a carta à ele ou cria novo com essa carta
    bool existe = false;
    int i;
    for(i = 0; i < this->getNumAtualJogadores(); ++i){
        if(nomeJogador == this->_jogadores[i].getNomeJogador()){
            existe = true;
            break;
        }
    }

    if(existe) { // só add a carta para ele
        this->_jogadores[i].adicionaCarta(card);
    } else {
        // cria e configura o novo jogador
        Jogador* p_jog = new Jogador();
        p_jog->setNomeJogador(nomeJogador);
        p_jog->adicionaCarta(card);
        Jogador jog = *p_jog;

        if(this->_atualSize != 0){
            Jogador* vet = this->getJogadores();
            Jogador* p_vetor = new Jogador[this->_atualSize + 1];

            for(int k = 0; k < _atualSize; ++k) {
                p_vetor[k] = vet[k];
            }
            p_vetor[this->_atualSize] = jog;

            // agora joga ele na Partida
            this->setJogadores(p_vetor);
            this->_atualSize++;
        } else {
            // agora joga ele na Partida
            this->setJogadores(p_jog);
            this->_atualSize++;
        }
    }
}

int Partida::getNumJogadores() {
    return this->_num_jogadores;
}

int Partida::getNumAtualJogadores() {
    return this->_atualSize;
}

//  parâmetro: é o VETOR INTEIRO JÁ que passamos para o método
void Partida::setJogadores(Jogador* jogadores) { 
    this->_jogadores = jogadores;
}

Jogador* Partida::getJogadores() {
    return this->_jogadores;
}

Jogador Partida::getCampeao() {
    int pontoMax = 0;
    Jogador* vet = new Jogador[this->_atualSize];
    for(int i = 0; i < this->_atualSize; ++i) {
        int pontoAtual = this->_jogadores[i].calcularPontuacao();
        if(pontoAtual >= pontoMax) {
            pontoMax = pontoAtual;  
        }
    }

    vet = this->getJogadores();

    for(int i = 0; i < this->_atualSize; ++i) {
        if(this->_jogadores[i].calcularPontuacao() == pontoMax){
            Jogador campeao = vet[i];
            return campeao;
        }
    }
}

Jogador* Partida::getJogadoresOrdenados() {
    int pontos[this->_atualSize];

    for(int i = 0; i < this->_atualSize; ++i) {
        pontos[i] = this->_jogadores[i].calcularPontuacao();
    }

    // coloca em ordem crescente
    for(int i = 0; i < this->_atualSize; i++) {     
        int temp;
        for (int j = i + 1; j < this->_atualSize; j++) {     
           if(pontos[i] > pontos[j]) {    
               temp = pontos[i];    
               pontos[i] = pontos[j];    
               pontos[j] = temp;    
           }     
        }     
    }

    // agora pega os jogadores de acordo com a pontuação, em ordem
    Jogador* ans = new Jogador[_atualSize];
    Jogador* vet = this->getJogadores();
    for(int i = 0; i < this->_atualSize; i++) {   
        for(int j = 0; j < this->_atualSize; ++j) {
            if(vet[j].calcularPontuacao() == pontos[i]){
                ans[i] = vet[j];
                break;
            }
        }
    }

    return ans;
}

void Partida::imprimeJogadoresOrdenados() {
    Jogador* ans = new Jogador[this->_atualSize];

    ans = this->getJogadoresOrdenados();

    for(int i = 0; i < this->_atualSize; i++) {
        cout << ans[i].getNomeJogador() << " " << ans[i].calcularPontuacao() << endl;
    }
}