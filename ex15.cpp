#include <cmath>
#include <iostream>
#include <iomanip>

#define E 2.71828

using namespace std;

double f(double x, double y);

int main(void) {

    cout << fixed << setprecision(6);

    unsigned int cont = 6;
    unsigned int squares = 1;

    while (cont) {
        
        // calcula as partições
        double n = sqrt(squares);

        // divide os eixos pelas partições e pega o ponto médio
        double median = 1 / (double) (2 * n);
        double squareArea = pow(1 / (double) n, 2);

        double volume = 0;

        for (double x = median; x < 1; x += 2 * median) {
            for (double y = median; y < 1; y += 2 * median) {
                volume += (f(x, y) * squareArea);
            }
        }
        
        cout << "Integral " << squares << " squares = " << volume << endl;

        squares *= 4;
        cont--;
    }

    return 0;
};

double f(double x, double y) {
    return sqrt(1 + x * pow(E, y * (-1)));
}