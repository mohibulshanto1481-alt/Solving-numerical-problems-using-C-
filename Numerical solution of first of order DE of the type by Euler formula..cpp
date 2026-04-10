
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x,double y){
	return ((y-x)/(y+x));

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
			   yf=yi+h*fx;
		       xi=xi+h;
		       yi=yf;
		      cout<<setw(5)<<xi<<setw(10)<<fx<<setw(10)<<yf<<endl;
		
	}
	cout<<"yf="<<yf<<endl;	
	
	
return 0;
}

