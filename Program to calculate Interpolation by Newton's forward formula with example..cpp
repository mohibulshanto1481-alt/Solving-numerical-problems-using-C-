#include<iostream>
#include<iomanip>
using namespace std;


double F(double x) {
    return x*x*x + 2*x*x + 3*x + 5;
}


long long factorial(int n) {
    long long f = 1;
    for(int i=2;i<=n;i++) f*=i;
    return f;
}


void buildDifferenceTable(double y[20][20], int n) {
    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }
}

// Newton Forward Interpolation
double newtonForward(double x[], double y[20][20], int n, double xp){
    double h = x[1]-x[0];
    double u = (xp-x[0])/h;

   
    double result = y[0][0];


    double term = 1;
    for(int j=1;j<n;j++){
        term *= (u-(j-1));
        result += (term*y[0][j])/factorial(j);
        
    }
    return result;
}

int main(){
    int si;
    while(true){
        cout << "Enter the serial number : ";
        cin >> si;
        if(si == 0) break;

        int n;
        cout << "Enter number of data points: ";
        cin >> n;

        double x[20], y[20][20];

        cout << "Enter x values:\n";
        for(int i=0;i<n;i++){
            cin >> x[i];
            y[i][0] = F(x[i]); // generate y values
        }

        // Build forward difference table
        buildDifferenceTable(y,n);

        // Print forward difference table
        cout << "\nForward Difference Table:\n";
        for(int i=0;i<n;i++){
            cout << setw(5) << x[i] << "\t";
            for(int j=0;j<n-i;j++){
                cout << setw(10) << y[i][j] << "\t";
            }
            cout << endl;
        }

        double xp;
        cout << "\nEnter the value of x for interpolation: ";
        cin >> xp;

        double yp = newtonForward(x, y, n, xp);
        cout << "\nInterpolated value at x = " << xp << " is: " << yp << endl << endl;
    }

    return 0;
}

