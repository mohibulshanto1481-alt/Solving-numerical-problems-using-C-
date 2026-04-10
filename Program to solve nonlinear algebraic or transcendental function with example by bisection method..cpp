#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x, double y) { 
   return x*x + y*y - 4; 
   }
double g(double x, double y) { 
   return exp(x) + y - 1; 
   }

int main() {
	int i;
	double x_anl=-1.8163;
	double y_anl=0.8374;
	while(true){
		cout<<"enter the serial number:";
		cin>>i;
		if(i==0)break;
	
    double x,y,tol;
    cout<<"Enter the initial guess for X and Y:"<<endl;
    cin>>x>>y;
    cout<<"enter tolenrace value:";
    cin>>tol;
    
    int max_j;
    cout<<"how many numbers of iterations you want?please,enter the value:";
    cin>>max_j;

    cout << fixed << setprecision(4);
    cout << left; 

    cout << setw(12) << "Iteration"
         << setw(15) << "X_approx"
         << setw(15) << "Y_approx"
         << setw(15) << "ERROR of X"
         << setw(15) << "ERROR of Y" << endl;


    for (int j = 1; j <= max_j; j++) {
        double F = f(x,y);
        double G = g(x,y);

        // Jacobian
        double fx = 2*x;
        double fy = 2*y;
        double gx = exp(x);
        double gy = 1;
        double D = fx*gy - fy*gx;
        if( D==0){
        	cout<<"Does not converge"<<endl;
		}
		else{
	

        // Newton-Raphson increments
        double h = (-F*gy + fy*G)/D;
        double k = (-fx*G + F*gx)/D;

        // Update variables
        x += h;
        y += k;

        // Percentage error based on functional value (residual)
        double err_x = abs((x_anl-x)/x_anl)*100;
        double err_y = abs((y_anl-y)/y_anl)*100;

            cout << setw(12) << j
         << setw(15) << x
         << setw(15) << y
         << setw(15) << err_x
         << setw(15) << err_y << endl;
         
        
        if (err_x < tol*100 && err_y < tol*100) {
            cout << "\nConverged to root: x = " << x << ", y = " << y << endl;
            break;
        } }} }
    return 0;
}



