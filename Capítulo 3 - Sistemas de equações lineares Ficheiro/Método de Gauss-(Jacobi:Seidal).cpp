#include <iostream>
#include <vector>

using namespace std;

//Gauss-(Jacobi/Seidal)

double f1(double x1, double x2, double x3) {
	return 10 * x1 + 2 * x2 + x3 -7;
}
double f2(double x1, double x2, double x3) {
	return x1 + 5 * x2 + x3 +8;
}
double f3(double x1, double x2, double x3) {
	return 2 * x1 + 3 * x2 + 10 * x3-6;
}

int main() {
	double x1 = 0, x2 = 0, x3 = 0, x1t = 0, x2t = 0, x3t = 0, x11, x22, x33;

	do {
		x1t = x1;
		x2t = x2;
		x3t = x3;

		x11 = (7 - 2 * x2t - x3t)/10;
		x22 = (-8 - x1t - x3t) / 5;
		x33 = (6 - 2 * x1t - 3 * x2t) / 10;

		// Gauss-Seidel
		//x11 = (7 - 2 * x22 - x33) / 10;
		//x22 = (-8 - x11 - x33) / 5;
		//x33 = (6 - 2 * x11 - 3 * x22) / 10;

		x1 = x11;
		x2 = x22;
		x3 = x33;
		
	} while (abs((x1 - x1t) / x1) > 0.0005 || abs((x2 - x2t) / x2) > 0.0005 || abs((x3 - x3t) / x3) > 0.0005);


	cout << "x1: " << x1 << endl;
	cout << "x2: " << x2 << endl;
	cout << "x3: " << x3 << endl;
	cout << "residuo 1: " << f1(x1, x2, x3) << endl;
	cout << "residuo 2: " << f2(x1, x2, x3) << endl;
	cout << "residuo 3: " << f3(x1, x2, x3) << endl;

	system("pause");
}