
#include <iostream>
#include <iomanip>
using namespace std;

// Function to perform Gauss Elimination
void gaussElimination(double a[10][10], int n) {
    double x[10];

    // Forward elimination
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            double ratio = a[j][i] / a[i][i];
            for(int k=i; k<=n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back substitution
    x[n-1] = a[n-1][n] / a[n-1][n-1];
    for(int i=n-2; i>=0; i--) {
        double sum = 0;
        for(int j=i+1; j<n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Display solution
    cout << "\nSolution:\n";
    for(int i=0; i<n; i++) {
        cout << "x" << i+1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }
}

int main() {
    int si,n;
    while(true){
        cout << "Enter serial number (0 to exit): ";
        cin >> si;
        if(si == 0) break;

        cout<<"Enter the number of equation (n)=";
        cin>>n;
		
        double a[10][10];

        cout << "Enter coefficients of the system (augmented matrix):\n";
        cout << "Format: a*x + b*y + c*z = d\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<=n; j++) {
                cin >> a[i][j];
            }
        }

        gaussElimination(a, n);
        cout << endl;
    }

    return 0;
}

