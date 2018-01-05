#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return pow(x,3)-10*sin(x)+2.8;
}


int main () {
    double a = 1.5, b = 4.2,m;
    int iteracoes = 0;

    do{
        cout << "Iteracao " << iteracoes << endl;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;

        m=(a+b)/2;
        if(f(a)*f(m)<0)
            b=m;
        else
            a=m;

        iteracoes++;
    }while(iteracoes < 3);
    
    return 0;
}