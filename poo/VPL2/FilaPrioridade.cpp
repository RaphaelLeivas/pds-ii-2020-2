#include "FilaPrioridade.hpp"
#include "No.hpp"
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

FilaPrioridade::FilaPrioridade() {
    this->_tamanho = 0;
    this->_cabeca = nullptr;
}

void FilaPrioridade::inserir(int prioridade, int dado) {
    // primeira coisa é criar novo nó
    No* p_newNo = new No(prioridade, dado, nullptr);
    // por enquanto deixa nullptr até descobrir quem e o prox

    // cria o vetor com as pessoas na fila
    if(this->estaVazio() == true) {
        No* fila = p_newNo;
        // falta setar quem é o proximo!

        this->_cabeca = fila;
    } else {
        No* fila = new No[this->getTamanho() + 1];
        No* atual = this->getCabeca();
        for(unsigned i = 0; i < this->getTamanho(); ++i) {
            fila[i] = atual[i];
        }
        No newNo = *p_newNo;
        fila[this->getTamanho()] = newNo;

        // com os nós inseridos, falta ORDERNAR conforme prioridade
        // e depois jogar no this->_cabeca
        for(unsigned i = 0; i < this->getTamanho() + 1; ++i) {
            No temp;
            for(unsigned j = i + 1; j < this->getTamanho() + 1; ++j) {
                if(fila[i].getPrioridade() > fila[j].getPrioridade()) {
                    temp = fila[i];    
                    fila[i] = fila[j];    
                    fila[j] = temp; 
                }
            }
        }
        this->_cabeca = fila;
    }

    setTamanho(++this->_tamanho);
}

unsigned FilaPrioridade::getTamanho() {
    return this->_tamanho;
}

No* FilaPrioridade::getCabeca() {
    return this->_cabeca;
}

void FilaPrioridade::setTamanho(int tamanho) {
    this->_tamanho = tamanho;
}

// deve printar SOMENTE OS DADOS!
void FilaPrioridade::print() {
    No* fila = this->getCabeca();
    for(int i = 0; i < this->_tamanho; ++i) {
        cout  << fila[i].getDado() << " ";
    }
}

int FilaPrioridade::remover() {
    No* first = this->getCabeca();

    No* fila = new No[this->getTamanho()];
    for(unsigned i = 0; i < this->getTamanho() - 1; ++i) {
        fila[i] = first[i + 1];
    }

    this->_cabeca = fila;
    this->setTamanho(this->getTamanho() - 1);

    return first->getDado();
}

bool FilaPrioridade::estaVazio() {
    if(this->_tamanho == 0) return true;
    else return false;
}

unsigned FilaPrioridade::getMeio() {
    int middleIndex = this->getTamanho() / 2;
    No* fila = this->getCabeca();

    return fila[middleIndex].getDado();
}

unsigned FilaPrioridade::getUltimo() {
    No* fila = this->getCabeca();

    return fila[this->getTamanho() - 1].getDado();
}

void FilaPrioridade::furaFila(int dado) {
    No* first = this->getCabeca();
    int minPriority = first->getPrioridade();

    this->inserir(minPriority - 1, dado);
}