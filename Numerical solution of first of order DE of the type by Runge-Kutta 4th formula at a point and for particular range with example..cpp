

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x,double y){
	return 1+pow(y,2);

}

int main(){
	
	int n;
	double xi,yi,h,xf;
	cout<<"xi,yi,h,xf:";
	cin>>xi>>yi>>h>>xf;
	
    n=round((xf-xi)/h);
	double yf;
	cout<<setw(5)<<"X"<<setw(10)<<"F(x,y)"<<setw(10)<<"Y"<<endl;
	
	for(int i=0;i<n;i++){
		double k1=h*f(xi,yi);
		double k2=h*f(xi+h/2.0,yi+k1/2.0);
		double k3=h*f(xi+h/2.0,yi+k2/2.0);
		double k4=h*f(xi+h,yi+k3);
		       yf=yi+((1.0)/(6.0))*(k1+2*k2+2*k3+k4);

		     
			   xi=xi+h;
		       yi=yf;
		      cout<<setw(5)<<xi<<setw(10)<<k1<<setw(10)<<yf<<endl;
		
	}
	cout<<endl;
	cout<<endl;
	cout<<"yf="<<yf<<endl;	
	
	
return 0;
}

