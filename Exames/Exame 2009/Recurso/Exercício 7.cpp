#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return exp(1.5*x);
}

double simpson(double a, double b, double h, double n){
    double ss = 0.0;
    for(int i = 0.0; i <= n; i++){
        if(i == 0)
            ss = f(a);
        else if(i == n)
            ss += f(b);
        else if((i%2) == 0)
            ss += 2.0*f(a+h*i);
        else
            ss+= 4.0*f(a+h*i);
    }
    ss = ss * (h/3.0);
    return ss;
}

int main () {
    double a=2.5, b=3.0, h=0.125, n =(b-a)/h;
    double i, il, ill;
    cout << fixed << setprecision(5);
    cout << "h: " << h << endl;
    i = simpson(a,b,h,n);
    cout << "I: " <<  i << endl;
    cout << endl;

    h = h/2;
    n =(b-a)/h;
    cout << "h: " << h << endl;
    il = simpson(a,b,h,n);
    cout << "I': " << il << endl;
    cout << endl;

    h = h/2;
    n =(b-a)/h;
    cout << "h: " << h << endl;
    ill = simpson(a,b,h,n);
    cout << "I'': " << ill << endl;
    cout << endl;

    cout << "QC: " << (il-i)/(ill-il) << endl;
    cout << fixed << setprecision(8);
    cout << "erro: " << abs((ill-il)/15.0) << endl;

    //b) 31.66403286697275
    //c) |31.66403286697275 - (31.66425+31.66405+31.66403)/3| = 7.713302724710047*10^-5
    //d) 2 casas pq valor do erro relativo estimado = 0.00000085 e erro relativo calculado = 0.000077
    return 0;
}
