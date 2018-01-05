#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return exp(x)-4*pow(x,2);
}

double recorrencia(double x){
    return 2.0*log(2.0*x);
}


int main () {
    double x = 1.1; //guess
    int iteracao = 0;
    double x0 = x;
    double x1 = recorrencia (x0);
    cout << "Iteracao 0:" << endl;
    cout << "x: " << x0 << endl;
    cout << "Iteracao 1:" << endl;
    cout << "x: " << x1 << endl;
    cout << "Residuo: " << x1-x0 << endl;
    return 0;
}