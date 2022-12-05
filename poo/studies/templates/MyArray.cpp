#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Array personalizado que armazena {@N} itens de uma classe {@T}
 * 
 * @tparam T 
 * @tparam N 
 */
template <class T, int N> class MyArray {
    T members[N]; // N itens da classe T
  public:
    MyArray() = default; // construtor padrão

    void setValue(unsigned int index, T value) {
      if(index < 0 || index >= N) {
        cout << "Acesso a posição inválida de MyArray!";
        exit(1);
      }

      members[index] = value;
    }

    T getValue(unsigned int index) {
      if(index < 0 || index >= N) {
        cout << "Acesso a posição inválida de MyArray!";
        exit(1);
      }

      return members[index];
    }
};