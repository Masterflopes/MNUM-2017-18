#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return sqrt(1+pow(1.5*exp(1.5*x),2));
}

double trapezio(double a, double b, double h, double n){
    double st = 0;
    for(int i = 0; i <= n; i++){
        if(i==0)
            st += f(a);
        else if(i==n)
            st+=f(b);
        else
            st+=2*f(a+h*i);
    }
    st = st * (h/2);
    return st;
}

double simpson(double a, double b, double h, double n){
    double ss = 0;
    for(int i = 0; i <= n; i++){
        if(i==0)
            ss += f(a);
        else if(i==n)
            ss+=f(b);
        else if((i%2)==0)
            ss+=2.0*f(a+h*i);
        else
            ss+=4.0*f(a+h*i);
    }
    ss = ss * (h/3.0);
    return ss;
}

int main () {
    double a=0,b=2,h=0.5,n=(b-a)/h;
    double ss, ssl, ssll,st,stl,stll, qcs,qct,erros,errot;
    cout << fixed << setprecision (6);

    st = trapezio(a,b,h,n);
    ss = simpson(a,b,h,n);

    h = h/2;
    n = (b-a)/h;
    stl = trapezio(a,b,h,n);
    ssl = simpson(a,b,h,n);

    h = h/2;
    n = (b-a)/h;
    stll = trapezio(a,b,h,n);
    ssll = simpson(a,b,h,n);

    qct = (stl-st)/(stll-stl);
    errot = (stll-stl)/3;

    qcs = (ssl-ss)/(ssll-ssl);
    erros = (ssll-ssl)/15;

    cout << "Trapezio" << endl;
    cout << "I: " << st << endl;
    cout << "I': " << stl << endl;
    cout << "I'': " << stll << endl;
    cout << "QC: " << qct << endl;
    cout << "Erro: " << errot << endl;
    cout << endl;
    cout << "Simpson" << endl;
    cout << "I: " << ss << endl;
    cout << "I': " << ssl << endl;
    cout << "I'': " << ssll << endl;
    cout << "QC: " << qcs << endl;
    cout << "Erro: " << erros << endl;
    return 0;
}
