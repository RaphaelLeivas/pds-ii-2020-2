/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  // para que dois polígonos sejam iguais, todo ponto de 
  // lhs deve possuir um ponto IGUAL em rhs (CASO 1)
  // EXCETO para RightRectangle (CASO 2)

  // como NUNCA vou consiguir acessar NADA de Polygon por causa do
  // INFERNO do protected, usa a GAMBIARRA HORRÍVEL de que
  // todo polígono pode ser expresso como um vetor de Point

  std::vector<Point> pointsLhs = lhs;
  std::vector<Point> pointsRhs = rhs;

  // caso 1: polígono qualquer
  bool ansCase1 = true;
  for(unsigned int i = 0; i < pointsLhs.size(); ++i) {
    bool found = false;
    for(unsigned int j = 0; j < pointsRhs.size(); ++j) {
      // pega os pontos
      Point pLhs = pointsLhs[i];
      Point pRhs = pointsRhs[j];

      if(pLhs.x == pRhs.x && pLhs.y == pRhs.y)
        found = true;
    }
    if(found == false)
      ansCase1 = false;
  }

  // caso 2: RightRectangle
  bool ansCase2 = true;

  // caso 2.1 retângulo normal -> daria TRUE no Caso 1

  // caso 2.2 retângulo do lhs igual ao reverso do rhs
  // if(pointsLhs[0].x == pointsLhs[0].x + (points))
  
  
  return ansCase1 && ansCase2;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  std::vector<Point> limits = *this; // acessa o limits
  bool xContain = false, yContain = false;

  int x1 = limits[0].x, y1 = limits[0].y, x2 = limits[1].x, y2 = limits[1].y;
  int xp = p.x, yp = p.y;

  if(x1 <= x2) { // normalmente
    if(xp >= x1 && xp <= x2) xContain = true;
  } else { // caso anormal
    if(xp <= x1 && xp >= x2) xContain = true;
  }

  if(y1 <= y2) { // normalmente
    if(yp >= y1 && yp <= y2) yContain = true;
  } else { // caso anormal
    if(yp <= y1 && yp >= y2) yContain = true;
  }

  return xContain && yContain;
}

Point::Point(int xx, int yy): x(xx), y(yy) { // construtor de Point

}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  Point* p1_p = new Point(x0, y0);
  Point* p2_p = new Point(x1, y1);

  Point p1 = *p1_p;
  Point p2 = *p2_p;

  limits.push_back(p1);
  limits.push_back(p2);
}