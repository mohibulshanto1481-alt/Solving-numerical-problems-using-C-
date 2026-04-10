////PROGRAM TO CHECK WHETHER ANY GIVEN IS PRIME OR NOT.WRITE CODES FOR BOTH WITH USER DEFINED FUNCTION.

#include <iostream>
using namespace std;
bool isprime(int n){
	if(n<=1)return false;
	for(int i=2;i<=n/2;i++)
	{
		if (n%i==0)return false;
	
	}
	return true;
}

int main() {
    int n,si;

    while(true){
    	cout<<"ENTER THE VALUE OF SERIAL NUMBER"<<endl;
    	cin>>si;
    	if(si==0)break; 
    cout << "Enter the value of n: ";
    cin >>n;


    if(isprime(n)){
    	cout<<n<<" is a prime number."<<endl;
	}
	else
	{
		cout<<n<<" is not a prime number."<<endl;
	}
    
	}
    return 0;
}

