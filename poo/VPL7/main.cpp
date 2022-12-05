#include <iostream>

#include "RingArray.h"

using namespace std;

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value) {
  // o _last fala qual o proximo indice livre
  // o _first fala qual o indice do cara mais antigo, que vai sair

  if(this->isFull()) {
    cout << "Erro: anel cheio." << endl;
    exit(1);
  }

  this->buf[this->_last] = value;
  this->_last++;

}

template <class T, unsigned N>
T RingArray<T, N>::get() {

  if(this->isEmpty()) {
    cout << "Erro: anel vazio." << endl;
    exit(1);
  }

  // salva a resposta
  T ans = this->buf[this->_first];

  // todo munda anda para frente, já que tirou o primeiro
  for(unsigned i = 1; i < N; ++i) {
    this->buf[i - 1] = this->buf[i];
  }
  this->_last--;
  return ans;

}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const {
  if(this->_last == N - 1) return true; 
  else return false;
}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const {
  if(this->_last == 0) return true; 
  else return false;
}

template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value) {
    r.add(value);
  }
  while (!r.isEmpty()) {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get() {
  RingArray<T, 8> r; // cria um vetor com OITO espaços sempre, em todos os testes.
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}

int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }

  // char num;
  // RingArray<char, 8> r; // cria um vetor com OITO espaços sempre, em todos os testes.
  // while(cin >> num) {
  //   if(num == '0') break;
  //   r.add(num);
  //   for(int i = 0; i < 8; ++i) {
  //     cout << r.buf[i] << " ";
  //   }
  //   cout << endl;
  // }

  // // agora retorna
  // while(1) {
  //   cout << r.get() << endl;
  // }

  return 0;
}