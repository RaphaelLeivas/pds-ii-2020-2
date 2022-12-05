#include "queue.h"

struct Node {
  int _key; // o valor da posição
  Node* _next; // indica o próximo da fila

  Node(int key, Node* next) { // construtor
    this->_key = key;
    this->_next = next;
  };
  Node(); // constrtor padrao
};

Queue::Queue() {
  this->_front = nullptr;
  this->_back = nullptr;
}

void Queue::push(int k) {
  Node* newNo = new Node(k, this->_back);

  this->_back = newNo;
  if(this->_front == nullptr) 
    this->_front = this->_back;
}

void Queue::pop() {
  Node* last = this->_back;
  Node* check = new Node(0, nullptr);

  if(this->count() == 0){
    throw EmptyException();
  }

  while(true) {
    check = last->_next; // PROBLEMA se last é nullptr

    if(check == nullptr) { // last é o unico na lista
      // esvazia a lista
      this->_front = nullptr;
      this->_back = nullptr;

      break;
    }

    if(check->_next == nullptr) 
      break;

    last = last->_next;
  }
  
  // ao sair do while, last é o segundo colocado
  last->_next = nullptr;
  this->_front = last;

  return;
}

int Queue::front() const {
  int ans = 0;

  if(this->count() == 0){
    throw EmptyException();
  }

  ans = (this->_front)->_key;

  return ans;
}

int Queue::back() const {
  int ans = 0;
  
  if(this->count() == 0){
    throw EmptyException();
  }

  ans = (this->_back)->_key;

  return ans;

}

int Queue::count() const {
  unsigned int ans = 0;
  
  Node* last = this->_back;
  Node* check = new Node(0, nullptr);

  if(last == nullptr) // lista vazia
    return 0;

  while(check != nullptr) {
    check = last->_next;

    last = last->_next;
    ans++;
  }
  
  return ans; 
}