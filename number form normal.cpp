//PROGRAM TO FIND THE LARGEST AND SMALLEST NUMBER THAT CAN BE FORMED USING DIGITS OF THE GIVEN NUMBER.WRITE CODES FOR  USER DEFINED FUNCTION.
#include <iostream>
#include<string>
#include<cstring>

using namespace std;
void smallestNumber(string number,int size){
 //sorting in acsending order
	for(int i=0;i<size-1;i++){
		for (int j=i+1;j<size;j++){
		if (number[i]>number[j]){
		swap(number[i],number[j]);
	 	}
}
}
// If the input's first digit is '0', the program swaps it with the first non-zero digit found in the number before processing further.	
        if(number[0]=='0'){
		for(int i=1;i<=size;i++){          
        if(number[i]!='0'){     
	    swap(number[0],number[i]);
	    	break;
		   	}
		}
	}
		
	cout<<"smallest number= "<<number<<endl;
}
//sorting in descending order
void largestNumber(string number,int size){
	for(int j=0;j<= size-1;++j){
		for (int k=j+1;k<=size;++k){
			if (number[j]<number[k])
			swap(number[j],number[k]);
		}
	}
	cout<<"largest number= "<<number<<endl;
}
int main() 
{
	int si;
	while(true){
		cout<<"Enter the serial number:"<<endl;
		cin>>si;
		if(si==0)break;
 string number;
 cout<<"enter a number"<<endl;
 cin>>number;
 int size=number.size();
 smallestNumber(number,size);
 largestNumber(number,size);
}


	
	return 0;
} 

