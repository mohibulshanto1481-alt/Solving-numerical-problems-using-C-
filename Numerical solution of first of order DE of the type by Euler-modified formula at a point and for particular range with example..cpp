
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x,double y){
	return (2+sqrt(x*y));

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
		double fx=f(xi,yi);
		double y1=yi+h*fx;
		double fx1=f(xi+h,y1);
		double y2=yi+(h/2.0)*(fx+fx1);
		double fx2=f(xi+h,y2);
		double y3=yi+(h/2.0)*(fx+fx2);
		double fx3=f(xi+h,y3);
		yf=yi+(h/2.0)*(fx+fx2);
		       
		       

		     
			   xi=xi+h;
		       yi=yf;
		      cout<<setw(5)<<xi<<setw(10)<<fx<<setw(10)<<yf<<endl;
		
	}
	cout<<endl;
	cout<<endl;
	cout<<"yf="<<yf<<endl;	
	
	
return 0;
}

