
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


double u_x_0(double x) {
    const double pi = acos(-1);
    return sin(pi * x);
}
   // initial condition

int main()
{
    cout << fixed << setprecision(6);

    int i, j, m, n, option;
    double c, alpha, h, k, x, t;
    double x_i, x_f, t_i, t_f, u_i, u_f;

    cout << "Numerical solution of heat equation\n";

    cout << "Enter value of c: ";
    cin >> c;

    cout << "Enter initial x and u (u(x_i,t)): ";
    cin >> x_i >> u_i;

    cout << "Enter final x and u (u(x_f,t)): ";
    cin >> x_f >> u_f;

    t_i = 0.0;
    cout << "Enter final simulation time: ";
    cin >> t_f;

z:
    cout << "Enter h and k: ";
    cin >> h >> k;

    alpha = (c * c * k) / (h * h);

    if (alpha <= 0 || alpha > 0.5)
    {
        cout << "Invalid! alpha must be 0 < alpha <= 0.5\n";
        goto z;
    }

    m = (x_f - x_i) / h;
    n = (t_f - t_i) / k;

double u[n+1][m+1];  // ??? max size 100x100


    // Boundary conditions
    for (i = 0; i <= n; i++)
    {
        u[i][0] = u_i;
        u[i][m] = u_f;
    }

    // Initial condition
    for (j = 1; j <= m - 1; j++)
    {
        x = x_i + j * h;
        u[0][j] = u_x_0(x);
    }

    // Time marching (FTCS)
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            u[i + 1][j] =
                alpha * (u[i][j - 1] + u[i][j + 1])
                + (1 - 2 * alpha) * u[i][j];
        }
    }

    // Output options
    while (1)
    {
        cout << "\nChoose option:\n";
        cout << "1. x, t both vary\n";
        cout << "2. x vary, t constant\n";
        cout << "3. x constant, t vary\n";
        cout << "4. x, t both constant\n";
        cout << "0. Exit\n";

        cin >> option;
        if (option == 0) break;

        if (option == 1)
        {
            for (i = 0; i <= n; i++)
            {
                t = t_i + i * k;
                for (j = 0; j <= m; j++)
                {
                    x = x_i + j * h;
                    cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
                }
            }
        }
        else if (option == 2)
        {
            cout << "Enter t: ";
            cin >> t;
            i = (t - t_i) / k;

            for (j = 0; j <= m; j++)
            {
                x = x_i + j * h;
                cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
            }
        }
        else if (option == 3)
        {
            cout << "Enter x: ";
            cin >> x;
            j = (x - x_i) / h;

            for (i = 0; i <= n; i++)
            {
                t = t_i + i * k;
                cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
            }
        }
        else if (option == 4)
        {
            cout << "Enter x and t: ";
            cin >> x >> t;

            i = (t - t_i) / k;
            j = (x - x_i) / h;

            cout << "u(" << x << "," << t << ") = " << u[i][j] << endl;
        }
    }

    return 0;
}
