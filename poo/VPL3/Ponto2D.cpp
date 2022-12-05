#include "Ponto2D.hpp"

using namespace std;

double Ponto2D::distancia(Ponto* p) const {
    if(p->getDimensao() == 2) {
        Ponto2D* point2d = dynamic_cast<Ponto2D*>(p); // converte para Ponto2D

        double root1 = pow((this->getX() - point2d->getX()), 2);
        double root2 = pow((this->getY() - point2d->getY()), 2);

        double ans = sqrt(root1 + root2);

        return ans;
    }
 
}

void Ponto2D::converteParaPolar() {
    double r = sqrt(pow(this->getX(), 2) + pow(this->getY(), 2));
    double theta = atan(this->getY() / (double)this->getX());

    this->_x = r;
    this->_y = theta;
}

string Ponto2D::to_string() const {
    string xCoord = std::to_string(this->getX());
    string yCoord = std::to_string(this->getY());

    string ans = "(" + xCoord + "," + yCoord + ")";

    return ans;
}

Ponto2D::Ponto2D(double x, double y) {
    this->_x = x;
    this->_y = y;
}

Ponto2D::Ponto2D() = default;

double Ponto2D::getX() const {
    return this->_x;
}

double Ponto2D::getY() const {
    return this->_y;
}

int Ponto2D::getDimensao() const {
    return 2;
}

