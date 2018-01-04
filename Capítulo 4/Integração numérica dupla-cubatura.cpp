#include <iostream>
#include <cmath>

using namespace std;

//Integracao numerica dupla ou cubatura

double f(double x, double y) {
	return exp(y - x);
}

int main() {
	double nx = 2, ny = 2;
	double a = 0, b = 0.5;
	double hx = (b - a) / nx, hy = (b - a) / ny;

	double soma0 = f(0, 0) + f(0, 0.5) + f(0.5, 0) + f(0.5, 0.5);
	double soma1 = f(0, 0.25) + f(0.25, 0) + f(0.5, 0.25) + f(0.25, 0.5);
	double soma2 = f(0.25, 0.25);

	double st = hx*hy / 4 * (soma0 + 2 * soma1 + 4 * soma2);
	double ss = hx*hy / 9 * (soma0 + 4 * soma1 + 16 * soma2);

	cout << "st: " << st << endl;
	cout << "ss: " << ss << endl;

	system("pause");
}
