
#include <iostream>
using namespace std;

double F(double x) {
    return x*x + 2*x + 1;
}

// Function to compute Lagrange interpolation/extrapolation
double lagrange(double x[], double y[], int n, double xp) {
    double yp = 0;
    for(int i=0; i<n; i++) {
        double term = y[i];
        for(int j=0; j<n; j++) {
            if(j != i) term *= (xp - x[j]) / (x[i] - x[j]);
        }
        yp += term;
    }
    return yp;
}

int main() {
    int si;
    while(true){
        cout << "Enter serial number :";
        cin >> si;
        if(si==0) break;

        int n;
        cout << "Enter number of data points: ";
        cin >> n;

        double x[20], y[20];

        cout << "Enter x values: ";
        for(int i=0;i<n;i++) {
            cin >> x[i];
            y[i] = F(x[i]);  // automatically compute y
        }

        double xp;
        cout << "Enter the value of x to interpolate/extrapolate: ";
        cin >> xp;

        double yp = lagrange(x, y, n, xp);
        cout << "The value at x = " << xp << " is: " << yp << endl << endl;
    }
 return 0;
}

