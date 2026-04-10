
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

// Gauss-Seidel iteration function
void gaussSeidel(double a[10][10], double b[10], int n, int maxIter, double tol) {
    double x[10] = {0}; // Initial guess

    cout << fixed << setprecision(8);
    cout << "\nIteration Table:\n";
   
    cout << setw(10) << "Iteration";
    for(int i = 0; i < n; i++) {
    stringstream ss;
    ss << "X" << i+1 << "_approx";
    cout << setw(15) << ss.str();
}
cout << endl;


    for(int iter = 1; iter <= maxIter; iter++) {
        cout << setw(10) << iter;
        double x_old[10];
        for(int i=0; i<n; i++) x_old[i] = x[i];

        for(int i=0; i<n; i++) {
            double sum = 0;
            for(int j=0; j<n; j++) {
                if(j != i) sum += a[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / a[i][i];
            cout << setw(15) << x[i];
        }
        cout << endl;

        // Check convergence
        double maxDiff = 0;
        for(int i=0; i<n; i++) {
            double diff = fabs(x[i] - x_old[i]);
            if(diff > maxDiff) maxDiff = diff;
        }
        if(maxDiff < tol) break; // Convergence achieved
    }

    cout << "\nFinal approximation solution:\n";
    for(int i=0; i<n; i++) {
        cout << "X" << i+1 << " = " << x[i] << endl;
    }
}

int main() {
    int si;
    while(true){
        cout << "Enter serial number (0 to exit): ";
        cin >> si;
        if(si == 0) break;

        int n = 3; // Number of variables for 3x3 system
        double a[10][10], b[10];
        int maxIter;
        double tol;

        cout << "Enter coefficients of the system (augmented matrix format):\n";
        cout << "Format for each row: a*x + b*y + c*z = d\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> a[i][j];
            }
            cin >> b[i];
        }

        cout << "Enter maximum number of iterations: ";
        cin >> maxIter;
        cout << "Enter tolerance: ";
        cin >> tol;

        gaussSeidel(a, b, n, maxIter, tol);
        cout << endl;
    }

    return 0;
}



