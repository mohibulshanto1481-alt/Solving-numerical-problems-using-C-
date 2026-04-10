
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

// Jacobi iteration function
void jacobiIteration(double a[10][10], double b[10], int n, int maxIter, double tol) {
    double x[10] = {0}, x_new[10] = {0};

    cout << fixed << setprecision(8);
    cout << left;
    cout << "\nIteration Table:\n";
cout << setw(12) << "Iteration";
for(int i = 0; i < n; i++) {
    stringstream ss;
    ss << "X" << i+1 << "_approx";
    cout << setw(15) << ss.str();
}
cout << endl;

    for(int iter = 1; iter <= maxIter; iter++) {
        for(int i = 0; i < n; i++) {
            double sum = 0;
            for(int j = 0; j < n; j++) {
                if(j != i) sum += a[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum) / a[i][i];
        }

        // Print iteration values
        cout << setw(12) << iter;
        for(int i = 0; i < n; i++) {
            cout << setw(15) << x_new[i];
        }
        cout << endl;

        // Check for convergence
        double maxDiff = 0;
        for(int i = 0; i < n; i++) {
            double diff = fabs(x_new[i] - x[i]);
            if(diff > maxDiff) maxDiff = diff;
            x[i] = x_new[i]; // update for next iteration
        }

        if(maxDiff < tol) break; // convergence achieved
    }

    // Final solution
    cout << "\nFinal approximation solution:\n";
    for(int i = 0; i < n; i++) {
        cout << "X" << i+1 << " = " << x[i] << endl;
    }
}

int main() {
    int si;
    while(true){
        cout << "Enter serial number (0 to exit): ";
        cin >> si;
        if(si == 0) break;

        int n;
        cout << "Enter number of variables: ";
        cin >> n;

        double a[10][10], b[10];
        int maxIter;
        double tol;

        cout << "Enter coefficients of the system (augmented matrix):\n";
        cout << "Format: a1 a2 a3 ... b\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
            cin >> b[i];
        }

        cout << "Enter maximum number of iterations: ";
        cin >> maxIter;
        cout << "Enter tolerance: ";
        cin >> tol;

        jacobiIteration(a, b, n, maxIter, tol);
        cout << endl;
    }

    return 0;
}

