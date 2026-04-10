//CREATE AN OOP  TO CHECK WHETHER ANY GIVEN IS PRIME OR NOT..
#include <iostream>
using namespace std;
class prime
{
	private:
		
		int n;
		 
	public:
	prime(){
		
	cout << "Enter the any number : ";
	
    cin >>n;
		 }
		 	
		

void primeNum(){

	bool isprime=true;
    if(n<=1){

	isprime=false;
	
}
 else
 {
  for(int i=2;i<=n/2;i++){
    	if(n%i==0){
    	isprime=false;
    	break;
		} 
	}

	} 
    if(isprime){
    	cout<<n<<" is a prime number."<<endl;
	}
	else
	{
		cout<<n<<" is not a prime number."<<endl;
	}

}
};
int main(){
	int si;

    while(true){
    	cout<<"ENTER THE VALUE OF SERIAL NUMBER"<<endl;
    	cin>>si;
    	if(si==0)break;
    	
    	prime ss;
        ss.primeNum();

}
return 0;
}

