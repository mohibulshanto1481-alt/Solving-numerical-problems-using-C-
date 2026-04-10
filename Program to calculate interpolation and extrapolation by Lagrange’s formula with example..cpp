
#include <iostream>
#include <iomanip>
using namespace std;

double F(double x) {
    return x*x*x - 3*x*x + 4*x + 2;
}

void buildTable(double x[], double y[20][20], int n) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]);
        }
    }
}

double newtonDivided(double x[], double y[20][20], int n, double xp) {
    double sum = y[0][0];
    double term = 1;
    for (int i = 1; i < n; i++) {
        term *= (xp - x[i-1]);
        sum += term * y[0][i];
    }
    return sum;
}

int main() {
    int si;
    while (true) {
        cout << "Enter serial number :";
        cin >> si;
        if (si == 0) break;

        int n;
        cout << "Enter number of data points: ";
        cin >> n;

        double x[20], y[20][20];
        cout << "Enter x values: ";
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            y[i][0] = F(x[i]);
        }

        buildTable(x, y, n);

        cout << "\nDivided Difference Table:\n";
        for (int i = 0; i < n; i++) {
            cout << setw(5) << x[i] << "\t";
            for (int j = 0; j < n - i; j++) {
                cout << setw(12) << y[i][j] << "\t";
            }
            cout << endl;
        }

        double xp;
        cout << "\nEnter the value of x for interpolation/extrapolation: ";
        cin >> xp;

        double yp = newtonDivided(x, y, n, xp);
        cout << "\nInterpolated/Extrapolated value at x = " << xp << " is: " << yp << endl << endl;
    }
    return 0;
}

