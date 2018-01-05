#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return -x+60*cos(sqrt(x))+2;
}

double fd (double x){
    return -30.0*sin(sqrt(x))/sqrt(x)-1;
}

int main () {
    double x = 1.8;
    int iteracoes = 0;
    do{
        cout << "Iteracao " << iteracoes << endl;
        cout << "x: " << x << endl;
        cout << "f(x): " << f(x) << endl;
        cout << endl;
        x = x - f(x)/fd(x);
        iteracoes++;
    }while(iteracoes <3);
    
    return 0;
}
