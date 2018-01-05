#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f (double x){
    return sqrt(1.0+pow(2.5*exp(2.5*x),2.0));
}

double trapezios(double h, double a, double b, double n){
    double st = 0;
    for(int i = 0; i <= n; i++){
        if(i==0)
            st = f(a);
        else if(i==n)
            st += f(b);
        else
            st += 2*f(a+h*i);
    }
    st = st * (h/2);
    return st;
}

double simpson(double h, double a, double b, double n){
    double ss = 0;
    for(int i = 0; i <= n; i++){
        if(i == 0)
            ss = f(a);
        else if(i == n)
            ss += f(b);
        else if ((i % 2) == 0)
            ss += 2*f(a+h*i);
        else
            ss += 4*f(a+h*i);
    }
    ss = ss * (h/3);
    return ss;
}

int main () {
    double h = 0.125, a = 0, b = 1;
    double n = (b-a)/h;
    double hl = h/2, hll = hl/2;
    double nl = (b-a)/hl, nll = (b-a)/hll;

    cout << fixed;
    cout.precision(5);

    cout << "Metodo do Trapezio" << endl;
    cout << "h: " << h << endl;
    cout << "h': " << hl << endl;
    cout << "h'': " << hll << endl;
    cout << "I: " << trapezios(h,a,b,n) << endl;
    cout << "I': " << trapezios(hl,a,b,nl) << endl;
    cout << "I'': " << trapezios(hll,a,b,nll) << endl;
    cout << "Qc: " << (trapezios(hl,a,b,nl) - trapezios(h,a,b,n))/(trapezios(hll,a,b,nll) - trapezios(hl,a,b,nl)) << endl;
    cout << "Erro: " << abs(trapezios(hll,a,b,nll) - trapezios(hl,a,b,nl))/3 << endl;

    cout << endl;

    cout << "Metodo de Simpson" << endl;
    cout << "h: " << h << endl;
    cout << "h': " << hl << endl;
    cout << "h'': " << hll << endl;
    cout << "I: " << simpson(h,a,b,n) << endl;
    cout << "I': " << simpson(hl,a,b,nl) << endl;
    cout << "I'': " << simpson(hll,a,b,nll) << endl;
    cout << "Qc: " << (simpson(hl,a,b,nl) - simpson(h,a,b,n))/(simpson(hll,a,b,nll) - simpson(hl,a,b,nl)) << endl;
    cout.precision(10);
    cout << "Erro: " << abs(simpson(hll,a,b,nll) - simpson(hl,a,b,nl))/15 << endl;
    return 0;
}