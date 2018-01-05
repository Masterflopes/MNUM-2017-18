#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return sqrt(sqrt(4.0*pow(x,3.0)-x+1.0));
}


int main () {
    double x = 4.0;
    int iteracoes = 0;
    do{
        cout << "Iteracao " << iteracoes << endl;
        cout << "x: " << x << endl;
        x = f(x);
        iteracoes++;
    }while(iteracoes<3);
    return 0;
}