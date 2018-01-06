#include <iostream>

using namespace std;

void show_matrix(double a11,double a12,double a13,double a21,double a22,double a23,double a31,double a32,double a33,double b1,double b2,double b3){
    cout << setw(12) << a11 << setw(12) << a12 << setw(12) << a13 << setw(12) << b1 << endl;
    cout << setw(12) << a21 << setw(12) << a22 << setw(12) << a23 << setw(12) << b2 << endl;
    cout << setw(12) << a31 << setw(12) << a32 << setw(12) << a33 << setw(12) << b3 << endl;
}

int main() {
    double a11 = 7, a12 = 2, a13 = 0, a21 = 4, a22 = 10, a23 = 1, a31 = 5, a32 = -2, a33 = 8, b1 = -2.5721, b2 = -2.5721, b3 = -2.5721;

    //cout matriz inicial
    show_matrix(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);

    //primeiro ponto
    a12 = a12 / a11;
    a13 = a13 / a11;
    b1 = b1 / a11;
    a11 = a11 / a11;

    //segundo ponto
    a22 = a22 + (a12 * (-a21));
    a23 = a23 + (a13 * (-a21));
    b2 = b2 + (b1 * (-a21));
    a21 = a21 + (a11 * (-a21));
    a32 = a32 + (a12 * (-a31));
    a33 = a33 + (a13 * (-a31));
    b3 = b3 + (b1 * (-a31));
    a31 = a31 + (a11 * (-a31));

    //terceiro ponto
    a23 = a23 / a22;
    b2 = b2 / a22;
    a22 = a22 / a22;

    a33 = a33 + (a23 * (-a32));
    b3 = b3 + (b2 * (-a32));
    a32 = a32 + (a22 * (-a32));

    //quarto ponto

    b3 = b3 / a33;
    a33 = a33 / a33;

    //cout matriz diagonalizada
    cout << endl;
    show_matrix(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
    cout << endl;

    double x, y, z;
    z = b3;
    y = b2 - a23 * z;
    x = b1 - (a12*y + a13*z);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    
    return 0;
}