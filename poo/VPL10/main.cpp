#include <iostream>
#include <vector>

using namespace std;

class Error {
  private:
    string _stringComNomeCriativo;
  
  public:
    Error(string message) : _message(message) {}; // construtor, sintaxe 'member initialization list'
    string getError() {
      return this->_message;
    }
};

template <class T, int N> class BoundedArray {
  public:
    unsigned int usedIndex[N];
    void set(int index, T value) { // set {value} na posição {index}
      if(index >= N) {
        throw new Error("Erro: indice maior que arranjo.");
      } else if(index < 0) {
        throw new Error("Erro: indice negativo.");
      }
        
      buf[index] = value;
      usedIndex[index] = 1;
    }

    T get(int index) {
      if(index >= N) {
        throw new Error("Erro: indice maior que arranjo.");
      } else if(index < 0) {
        throw new Error("Erro: indice negativo.");
      } else if(usedIndex[index] != 1) {
        throw new Error("Erro: indice nao inicializado.");
      }

      return buf[index];
    }

  private:
    T buf[N];
};

template <class T> void testArray() {
  BoundedArray<T, 8> a;
  char action;
  while (std::cin >> action) {
    int index;
    std::cin >> index;
    try {
      if (action == 's') {
        T value;
        std::cin >> value;
        a.set(index, value);
      } else if (action == 'g') {
        std::cout << a.get(index) << std::endl;
      }
    } catch (Error* e) {
      cout << e->getError() << endl;
    } catch (...) {
      std::cerr << "Erro desconhecido." << std::endl;
    }
  }
}

int main() {
  char type;
  std::cin >> type;
  switch(type) {
    case 'd':
      testArray<double>();
      break;
    case 'i':
      testArray<int>();
      break;
    case 's':
      testArray<std::string>();
      break;
  }
  return 0;
}