#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return exp(x)-4*pow(x,2);
}

double recorrenciaA(double x){
    return (1.0/2.0)*sqrt(exp(x));
}

double recorrenciaB(double x){
    return exp(x)/(4*x);
}

double recorrenciaC(double x){
    return -(1.0/2.0)*sqrt(exp(x));
}

int main () {
    cout << "Recorrencia a)" << endl;
    cout << "X1: " << endl;
    cout << "-1: " << recorrenciaA(-1.0) << endl;
    cout << "0: " << recorrenciaA(0.0) << endl;
    cout << "X2: " << endl;
    cout << "0: " << recorrenciaA(0) << endl;
    cout << "1: " << recorrenciaA(1) << endl;
    cout << "X3: " << endl;
    cout << "4: " << recorrenciaA(4) << endl;
    cout << "5: " << recorrenciaA(5) << endl;
    //A formula de recorrencia a) converge para as raízes nos intervalos x1 e x2 pois os valores são inferiores a 1, como podemos ver acima

    cout << endl;
    cout << "Recorrencia b)" << endl;
    cout << "X1: " << endl;
    cout << "-1: " << recorrenciaB(-1.0) << endl;
    cout << "0: " << recorrenciaB(0.0) << endl;
    cout << "X2: " << endl;
    cout << "0: " << recorrenciaB(0) << endl;
    cout << "1: " << recorrenciaB(1) << endl;
    cout << "X3: " << endl;
    cout << "4: " << recorrenciaB(4) << endl;
    cout << "5: " << recorrenciaB(5) << endl;
    //A formula de recorrencia b) nao converge para nenhuma das raízes

    cout << endl;
    cout << "Recorrencia c)" << endl;
    cout << "X1: " << endl;
    cout << "-1: " << recorrenciaC(-1.0) << endl;
    cout << "0: " << recorrenciaC(0.0) << endl;
    cout << "X2: " << endl;
    cout << "0: " << recorrenciaC(0) << endl;
    cout << "1: " << recorrenciaC(1) << endl;
    cout << "X3: " << endl;
    cout << "4: " << recorrenciaC(4) << endl;
    cout << "5: " << recorrenciaC(5) << endl;
    //A formula de recorrencia c) converge para as raízes nos intervalos x1 e x2 pois os valores são inferiores a 1, como podemos ver acima
    
    return 0;
}