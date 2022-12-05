#ifndef NO
#define NO

#include <iostream>

using namespace std;

class No {
  private:
     int _dado;
     No * _proximo;
	int _prioridade;

  public:
     No(int prioridade, int dado, No* proximo);
     No();
     
     void setProximo(No *next);
    
     No* getProximo();
     
     int getDado();

     void setDado(int dado);
	
	int getPrioridade();

	void setPrioridade(int prioridade);
};

#endif