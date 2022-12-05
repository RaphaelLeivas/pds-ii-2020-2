#include <iostream>
#include <chrono>
#include <thread>

#include "game_of_life.h"
// random comment for git test #2
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono_literals;

void Print(const GameOfLife& g) {
  cout << "  "; 

  for (int i = 0; i < g.columns(); ++i) {
    cout << "- "; 
  }

  cout << endl;

  for (int i = 0; i < g.lines(); ++i) {
    cout << "| ";
    for (int j = 0; j < g.columns(); ++j) {
      if (g.alive(i, j)) {
        cout << "* "; 
      } else {
        cout << "  ";
      }
    }
    cout << "|" << endl;
  }

  cout << "  "; 
  for (int i = 0; i < g.columns(); ++i) {
    cout << "- "; 
  }
  cout << endl;
}

#include <memory>
#include <string>

using namespace std;

int main() {
  // Lê os dados.
  int iterations;

  cin >> iterations;

  int line, column;
  cin >> line >> column;

  GameOfLife g(line, column);

  try {
    while (cin >> line) {
      cin >> column;
      g.Enliven(line, column);
    }

    Print(g);
    
    // Executa o número esperado de iterações.
    while (iterations > 0) {
      g++; // avança na iteração dos jogos
      Print(g);
      std::this_thread::sleep_for(10ms);
      iterations--;
    }
  } catch (GameOfLife::InvalidCellException e) {
    cerr << "As coordenadas [" << e.line << ", " << e.column << "] não são de uma célula válida" << endl;
    return 1;
  } 
  
  return 0;
}