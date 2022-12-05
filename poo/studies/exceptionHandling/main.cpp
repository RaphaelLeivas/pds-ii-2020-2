#include<bits/stdc++.h>

using namespace std;

class Error {
  private:
    string _message;
    int _statusCode;

  public: 
    Error(string message) { this->_message = message; this->_statusCode = 500; };
    Error(); // construtor padrão
    // ~Error();
    string getMessage() { return this->_message; }
    int getStatus() { return this->_statusCode; }
};

class Fraction {
  private:
    int _num;
    int _den;

  public: 
    Fraction(int num, int den) { this->_num = num; this->_den = den; }
    double getValue() {
      if(this->_den == 0)
        throw new Error("Divide by zero not allowed."); // o metodo da classe SÓ DISPARA, SÓ THROW
                                                        // nao tem try catch na classe
      
      return this->_num / (double)this->_den;
    }
};

int main() {
  Fraction* f = new Fraction(-10, 0);

  try { // o try catch vem na main.cpp
    cout << f->getValue() << endl; // dispara o throw
  } catch (Error* e) { // pega o throw aqui
    cout << e->getMessage() << endl;
    cout << e->getStatus() << endl;
  }
  
  return 0;
}