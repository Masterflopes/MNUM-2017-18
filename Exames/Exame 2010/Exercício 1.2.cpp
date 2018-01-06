#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double recorrencia (double x){
    return 2.0*log(2.0*x);
}

int main () {
    double x = 0.9; //guess
    int iteracao = 0;

    do{
        cout << "Iteracao " << iteracao << endl;
        cout << "x: " << x << endl;
        x = recorrencia(x);

        iteracao++;
    }while (iteracao < 2);

    //resíduo -> 1.17557 - 0.9 = 0.27557
    return 0;
}
