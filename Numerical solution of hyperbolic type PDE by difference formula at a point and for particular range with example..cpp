
// Numerical solution of wave equation using explicit finite difference
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// Initial condition
double u_x_0(double x) {
	double pi=acos(-1);
    return sin(pi*x);  // f(x) = 4x - x^2
}

// Initial velocity
double du_dt(double x) {
    return 0; // g(x) = 0
}

int main() {
    cout << fixed << setprecision(6);

    double c, h, k, x_i, x_f, t_f, u_i, u_f;

    cout << "Numerical solution of wave equation\n";
    cout << "Enter value of c: ";
    cin >> c;

    cout << "Enter initial x and u (u(x_i,t)): ";
    cin >> x_i >> u_i;

    cout << "Enter final x and u (u(x_f,t)): ";
    cin >> x_f >> u_f;

    cout << "Enter final simulation time t_f: ";
    cin >> t_f;

    cout << "Enter space step h and time step k: ";
    cin >> h >> k;

    double alpha = c * k / h;
    if (alpha > 1) {
        cout << "Invalid! alpha = c*k/h > 1, reduce k or increase h\n";
        return 1;
    }

    int m = (x_f - x_i)/h;  
    int n = t_f/k;          

    
    double u[n+1][m+1];


    for(int i = 0; i <= n; i++) {
        u[i][0] = u_i;   // left boundary
        u[i][m] = u_f;   // right boundary
    }

    // Initial condition at t=0
    for(int j = 1; j < m; j++) {
        double x = x_i + j*h;
        u[0][j] = u_x_0(x);
    }

    // Second row using initial velocity
    for(int j = 1; j < m; j++) {
        double x = x_i + j*h;
        u[1][j] = 0.5*pow(alpha,2)*(u[0][j+1] + u[0][j-1]) 
                  + (1 - pow(alpha,2))*u[0][j] 
                  + k*du_dt(x);
    }

    // Time marching for 3rd to last row
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            u[i+1][j] = pow(alpha,2)*(u[i][j-1] + u[i][j+1])
                        + 2*(1 - pow(alpha,2))*u[i][j]
                        - u[i-1][j];
        }
    }

    // Output options
    int option;
    while(true) {
        cout << "\nChoose option:\n";
        cout << "1. x, t both vary\n";
        cout << "2. x vary, t constant\n";
        cout << "3. x constant, t vary\n";
        cout << "4. x, t both constant\n";
        cout << "0. Exit\n";
        cin >> option;
        if(option == 0) break;

        if(option == 1) {
            for(int i=0; i<=n; i++) {
                double t = i*k;
                for(int j=0; j<=m; j++) {
                    double x = x_i + j*h;
                    cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
                }
            }
        }
        else if(option == 2) {
            double t;
            cout << "Enter t: ";
            cin >> t;
            int i = t/k;
            for(int j=0; j<=m; j++) {
                double x = x_i + j*h;
                cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
            }
        }
        else if(option == 3) {
            double x;
            cout << "Enter x: ";
            cin >> x;
            int j = (x - x_i)/h;
            for(int i=0; i<=n; i++) {
                double t = i*k;
                cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
            }
        }
        else if(option == 4) {
            double x, t;
            cout << "Enter x and t: ";
            cin >> x >> t;
            int i = t/k;
            int j = (x - x_i)/h;
            cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
        }
    }

    return 0;
}

