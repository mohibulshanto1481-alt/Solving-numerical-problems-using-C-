
#include<iostream>
#include <cmath>
using namespace std;
int main() {
	
int n ,si;
while(true){
	cout<<"enter the serial number:";
	cin>>si;
	if(si==0) break;
double exact=2;
double a , b;
cout<<"enter the value of intervals(n),upper limits(b) and lower limit(a):";
cin>>n>>b>>a;
double h = (b - a)/n;
double sum=0.00;
for(int i=0; i<=n; i++) {
    double x = a + i*h;
    double fx = sin(x);
    if(i==0 || i==n) sum += fx;
    else if(i%2==0) sum += 2*fx;
    else sum += 4*fx;
}

double integral = (h/3)*sum;
cout << "Integral = " << integral << endl;

double errors;
errors=(fabs(integral-exact)/exact)*100;
cout<<"Percentage errors="<<errors<<endl;
}
return 0;
}

