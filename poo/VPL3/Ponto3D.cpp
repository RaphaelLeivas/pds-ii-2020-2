#include "Ponto3D.hpp"

using namespace std;

Ponto3D::Ponto3D(double x, double y, double z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Ponto3D::Ponto3D() = default;

double Ponto3D::getZ() const {
    return this->_z;
}

string Ponto3D::to_string() const {

}

double Ponto3D::distancia(Ponto* p) const {
    if(p->getDimensao() == 3) {
        Ponto3D* point3d = dynamic_cast<Ponto3D*>(p); // converte para Ponto3D
        
        double root1 = pow(this->getX() - point3d->getX(), 2);
        double root2 = pow(this->getY() - point3d->getY(), 2);
        double root3 = pow(this->getZ() - point3d->getZ(), 2);

        double ans = sqrt(root1 + root2 + root3);

        return ans;
    }
}

int Ponto3D::getDimensao() const {
    return 3;
}

