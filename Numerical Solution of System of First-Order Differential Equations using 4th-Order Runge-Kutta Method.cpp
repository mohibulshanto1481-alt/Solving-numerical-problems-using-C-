
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Define the system of equations
// dx/dt = x + 2y
// dy/dt = 3x + 2y

double f(double t, double x, double y) {
    return x + 2 * y;  // dx/dt
}

double g(double t, double x, double y) {
    return 3 * x + 2 * y;  // dy/dt
}

int main() {
    double t0, x0, y0, h, t_end;

    cout << "Enter initial values (t0, x0, y0): ";
    cin >> t0 >> x0 >> y0;
    cout << "Enter step size (h) and final t: ";
    cin >> h >> t_end;

    int n = (t_end - t0) / h;  // number of iterations

    cout << fixed << setprecision(5);
    cout <<left;
    cout << setw(5)<<"t0"<<"\t"
	     <<setw(9)<<"x0"<<"\t"
		 <<setw(9)<<"y0"<<endl;


    for (int i = 0; i <= n; i++) {
        double k1x = h * f(t0, x0, y0);
        double k1y = h * g(t0, x0, y0);

        double k2x = h * f(t0 + h / 2.0, x0 + k1x / 2.0, y0 + k1y / 2.0);
        double k2y = h * g(t0 + h / 2.0, x0 + k1x / 2.0, y0 + k1y / 2.0);

        double k3x = h * f(t0 + h / 2.0, x0 + k2x / 2.0, y0 + k2y / 2.0);
        double k3y = h * g(t0 + h / 2.0, x0 + k2x / 2.0, y0 + k2y / 2.0);

        double k4x = h * f(t0 + h, x0 + k3x, y0 + k3y);
        double k4y = h * g(t0 + h, x0 + k3x, y0 + k3y);

        double x1 = x0 + (1.0 / 6.0) * (k1x + 2 * k2x + 2 * k3x + k4x);
        double y1 = y0 + (1.0 / 6.0) * (k1y + 2 * k2y + 2 * k3y + k4y);

        cout << setw(5) << t0 << "\t"
             << setw(9) << x0 << "\t"
             << setw(9) << y0 << endl;

        t0 += h;
        x0 = x1;
        y0 = y1;
    }

    cout << " Final values: x(" << t_end << ") = " << x0 << ", y(" << t_end << ") = " << y0 << endl;

    return 0;
}

