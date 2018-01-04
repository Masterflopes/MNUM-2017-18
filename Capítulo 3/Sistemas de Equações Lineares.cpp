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



/*
int main() {
	vector <double> l, u, a;
	a[11] = 3;
	a[12] = 1;
	a[13] = -1;
	a[14] = 2;
	a[21] = -5;
	a[22] = 1;
	a[23] = 3;
	a[24] = -4;
	a[31] = 2;
	a[32] = 0;
	a[33] = 1;
	a[34] = -4;
	a[41] = 1;
	a[42] = -5;
	a[43] = 3;
	a[44] = -3;

	l[11] = 3;
	l[21] = -5;
	l[31] = 2;
	l[41] = 1;

	u[11] = 1;
	u[12] = 1.0/3;
	u[13] = -1.0/3;
	u[14] = 2.0/3;

	l[22] = a[22] - l[21] * u[12];

	u[23] = (a[23] - l[21] * u[13])/l[22];
	u[24] = (a[24] - l[21] * u[14])/l[22];

	l[32] = a[32] - l[31] * u[12];
	l[33] = a[33] - l[31] * u[13];

	u[34] = a[34] - l[31] * u[14] - l[32] * u[24];
	l[42] = a[42] - l[41] * u[12];
	l[43] = a[43] - l[41] * u[13]-l[42]*u[23];
	l[44] = a[44] - l[41] * u[14] - l[42] * u[24]- l[43] * u[34];

	double y1, y2, y3, y4, x1, x2, x3, x4;

	cout << "L:" << endl;
	cout << l[11] << "  " << 0 << "  " << 0 << "  " << 0 << endl;
	cout << l[21] << "  " << l[22] << "  " << 0 << "  " << 0 << endl;
	cout << l[31] << "  " << l[32] << "  " << l[33] << "  " << 0 << endl;
	cout << l[41] << "  " << l[42] << "  " << l[43] << "  " << l[44] << endl;

	system("pause");
}*/