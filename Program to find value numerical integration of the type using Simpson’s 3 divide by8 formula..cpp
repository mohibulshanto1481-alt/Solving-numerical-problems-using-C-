
#include <iostream>
#include <iomanip>
#include <cmath>     // for exp() and fabs()
using namespace std;

int main() {
    int n;
    double a, b;
    cout << fixed << setprecision(4);


    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n, multiple of 3): ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "Error: n must be a multiple of 3 for Simpson's 3/8 Rule." << endl;
        return 1;
    }

    double h = (b - a) / n;
    double x[n + 1], fx[n + 1];

    // Compute f(x) = e^x for each x
    for (int i = 0; i <= n; i++) {
        x[i] = a + i * h;
        fx[i] = exp(x[i]);
    }

    // Apply Simpson's 3/8 Rule
    double sum = fx[0] + fx[n];
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0)
            sum += 2 * fx[i];
        else
            sum += 3 * fx[i];
    }

    double integral = (3 * h / 8) * sum;

    // Exact value: e^x from a to b = e^b - e^a
    double exact = exp(b) - exp(a);

    // Percentage error
    double error = fabs((integral - exact) / exact) * 100;

    cout << "\nSimpson's 3/8 Rule Integration Result\n";
    
    cout << "a = " << a << ", b = " << b << ", n = " << n << endl;
    cout << "Numerical Result : " << integral << endl;
    cout << "Exact Result     : " << exact << endl;
    cout << "Percentage Error : " << error << " %" << endl;

    return 0;
}

