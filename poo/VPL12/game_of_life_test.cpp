#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "game_of_life.h"

TEST_CASE("Tests GameOfLife::Enliven(int i, int j)") {
  GameOfLife g(3, 3);
  g.Enliven(0, 0);
  g.Enliven(0, 2);
  g.Enliven(2, 0);
  g.Enliven(2, 2);
  g.Enliven(1, 1);

  // Checa se a céculas solicitadas estão vivas.
  CHECK(g.alive(0, 0));
  CHECK(g.alive(0, 2));
  CHECK(g.alive(2, 0));
  CHECK(g.alive(2, 2));
  CHECK(g.alive(1, 1));
     
  // Checa se as demais céculas continuam mortas.
  CHECK_FALSE(g.alive(0, 1));
  CHECK_FALSE(g.alive(1, 0));
  CHECK_FALSE(g.alive(1, 2));
  CHECK_FALSE(g.alive(2, 1));
}

TEST_CASE("Tests GameOfLife::Kill(int i, int j)") {
  GameOfLife g(3, 3);
  for (int i : {0, 1, 2}) {
      for (int j : {0, 1, 2}) {
        g.Enliven(i, j);
      }
  }

  // Mata um subconjunto de células.
  g.Kill(0, 0);
  g.Kill(0, 2);
  g.Kill(2, 0);
  g.Kill(2, 2);
  g.Kill(1, 1);

  // Checa se a céculas solicitadas estão mortas.
  CHECK_FALSE(g.alive(0, 0));
  CHECK_FALSE(g.alive(0, 2));
  CHECK_FALSE(g.alive(2, 0));
  CHECK_FALSE(g.alive(2, 2));
  CHECK_FALSE(g.alive(1, 1));
    
  // Checa se as demais céculas continuam vivas.
  CHECK(g.alive(0, 1));
  CHECK(g.alive(1, 0));
  CHECK(g.alive(1, 2));
  CHECK(g.alive(2, 1));
}

TEST_CASE("Tests GameOfLife::operator++(int)") {
  GameOfLife* gBegin = new GameOfLife(5, 5);
  GameOfLife* gEnd = new GameOfLife(5, 5);

  // seta gBegin a posicao inical que eu quero
  for (int i : {1, 2, 3}) {
      for (int j : {1, 2, 3}) {
      if(i == 1 && (j >= 1 && j <= 3)) {
        gBegin->Enliven(i, j);
        // checa se esta viva mesmo
        CHECK(gBegin->alive(i, j));
      }
        
      if(i == 2 && j == 2) {
        gBegin->Enliven(i, j);
        // checa se esta viva mesmo
        CHECK(gBegin->alive(i, j));
      }
        
    }
  }

  // seta gEnd a posicao final esperada
  for (int i : {0, 1, 2, 3}) {
      for (int j : {1, 2, 3}) {
      if((i == 1 || i == 2) && (j >= 1 && j <= 3)) {
        gEnd->Enliven(i, j);
        // checa se esta viva mesmo
        CHECK(gEnd->alive(i, j));
        CHECK(gEnd->alive(i, j));
        CHECK(gEnd->alive(i, j));
      }
        
      if(i == 0 && j == 2) {
        gEnd->Enliven(i, j);
        // checa se esta viva mesmo
        CHECK(gEnd->alive(i, j));
        CHECK(gEnd->alive(i, j));
      }
        
    }
  }

  // proxima iteracao 
  (*gBegin)++;

  // verifica se e esperado condiz com o que ocorreu
  for(int i = 0; i < gBegin->lines(); ++i) {
    for(int j = 0; j < gBegin->columns(); ++j) {
      if(gBegin->alive(i, j) != gEnd->alive(i, j)) {
        CHECK(false);
        // cout << i << "," << j << endl;
        // cout << gBegin->alive(i, j) << " != " << gEnd->alive(i, j) << endl;
        
        // cout << "--------------" << endl;
      }
      
    }
  }

  CHECK(true); // chegou ate aqui
}

TEST_CASE("Test the throwing of GameOfLife::OutOfBoundException") {
  GameOfLife g(3, 3);
  for (int i : {-1, 0, 3}) {
    for (int j : {-1, 0, 3}) {
      if (i != 0 || j != 0) {
        CHECK_THROWS_AS(g.Enliven(i, j), const GameOfLife::InvalidCellException&); 
        CHECK_THROWS_AS(g.Kill(i, j), const GameOfLife::InvalidCellException&);
        CHECK_THROWS_AS(g.alive(i, j), const GameOfLife::InvalidCellException&);
      }
    }
  }
  
}