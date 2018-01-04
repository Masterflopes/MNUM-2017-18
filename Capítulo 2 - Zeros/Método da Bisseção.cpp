#include <iostream>#include <cmath>using namespace std;

long double funcao(long double x) {	return x - 2 * log(x) - 5;}

// MÉTODO DA BISSECAOint main() {	double a = 3.0, b = 3.3;	double xn, xnt;	xn = (a*f(b) - b*f(a)) / (f(b) - f(a));	int counter = 0;	do {		xnt =  xn;		xn = (a + b) / 2;		if ((f(a)*f(xn)) < 0)			b = xn;		else			a = xn;		counter++;	} while ((abs((xn - xnt)/ xn) * 100) > 0.5);	cout << "a: " << a << endl;	cout << "b: " << b << endl;	cout << "xn: " << xn << endl;	cout << "f(a): " << f(a) << endl;	cout << "f(b): " << f(b) << endl;	cout << "f(xn): " << f(xn) << endl;	cout << "counter: " << counter << endl;	system("pause");}