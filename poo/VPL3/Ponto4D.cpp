#include "Ponto4D.hpp"

using namespace std;

Ponto4D::Ponto4D(double x, double y, double z, double w) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_w = w;
}

Ponto4D::Ponto4D() = default;

double Ponto4D::getW() const {
    return this->_w;
}

string Ponto4D::to_string() const {

}

double Ponto4D::distancia(Ponto* p) const{
    if(p->getDimensao() == 4) {
        Ponto4D* point3d = dynamic_cast<Ponto4D*>(p); // converte para Ponto4D
        
        double root1 = pow(this->getX() - point3d->getX(), 2);
        double root2 = pow(this->getY() - point3d->getY(), 2);
        double root3 = pow(this->getZ() - point3d->getZ(), 2);
        double root4 = pow(this->getW() - point3d->getW(), 2);

        double ans = sqrt(root1 + root2 + root3 + root4);

        return ans;
    }
}

int Ponto4D::getDimensao() const {
    return 4;
}