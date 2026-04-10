
#include <iostream>
#include <iomanip>
#include <vector>
#include<cmath>
using namespace std;


int main(){
    int n; 
    double x[20],y[20][20];
    cout<<"n=";
    cin>>n;
    for(int i=0;i<n;i++){
    	cout<<"enter x and f(x):";
    	cin>>x[i]>>y[i][0];
	}
    


    double dd[5][5] = {0};
    for(int i=0;i<n;i++) 
	  dd[i][0] = y[i][0];

    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            dd[i][j] = (dd[i+1][j-1]-dd[i][j-1])/(x[i+j]-x[i]);
        }
    }

    // Print table
    cout << "Divided Difference Table:\n";
    for(int i=0;i<n;i++){
        cout << setw(8) << x[i];
        for(int j=0;j<n-i;j++){
            cout << setw(12) << dd[i][j];
        }
        cout << endl;
    }

   
    cout << "\nDerivatives at points:\n";
    cout << setw(8) << "x" << setw(12) << "f'(x)" << setw(12) << "f''(x)" << setw(12) << "f'''(x)" << endl;

    for(int i=0;i<n;i++){
        double f1=0, f2=0, f3=0;

        // 1st derivative: f1 = sum of first order divided differences * factorial terms
        if(i+1<n) f1 = dd[i][1]; // forward
        if(i+2<n) f2 = 2*dd[i][2]; // 2nd derivative approx
        if(i+3<n) f3 = 6*dd[i][3]; // 3rd derivative approx

        cout << setw(8) << x[i]
             << setw(12) << f1
             << setw(12) << f2
             << setw(12) << f3
             << endl;
    }

    return 0;
}

