//Program to take input of a user name and consumed current units and print an electric bill which billing criteria is as follows 
//v) First 50 units has minimum charge 100tk 
//vi) Next 200 units cost 2.50 TK/unit
//vii) Next 250 units cost 3.50 TK/unit 
//viii)Units above 500 are charged at a rate 5.00TK/unit 
//Make sure you implement the idea using user-defined function. 
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

// Function to calculate the electric bill based on consumed units
void GetBill(double unit)
{
    double bill;
    if(unit <= 50)
        bill = 100;  // Minimum charge for first 50 units
    else if(unit > 50 && unit < 250)
        bill = 100 + (unit - 50) * 2.50;  // Charge for next 200 units
    else if(unit > 250 && unit < 500)
        bill = 100 + 200 * 2.50 + (unit - 250) * 3.50;  // Charge for next 250 units
    else if(unit > 500)
        bill = 100 + 200 * 2.50 + 250 * 3.50 + (unit - 500) * 5.00;  // Charge for units above 500
    
    // Print the calculated bill
    cout << "Your electric bill is: " << bill << "tk." << endl;
}

int main()
{
    cout<<fixed<<setprecision(2);  // Set precision for floating-point output
   
    char choice;  // Character to store user's choice to run the program again

    do
    {
        string name;  // Variable to store username
        double unit;  // Variable to store consumed units
        
        cout << "Enter the username (kindly put a space before the username):"<<endl;
        cin>>name;
	      // cin.ignore();  // Ignore the newline character left by previous input
        //getline(cin, name);  // Read the full name including spaces
        
        cout <<"Enter consumed current units: "<<endl;
        cin >> unit;

        // Greet the user
        cout << "Hello, Mr./Ms. " << name<<endl;

        GetBill(unit);  // Call the function to calculate and print the bill
        

        // Prompt the user to decide if they want to run the program again
        cout << "\nDo you want to run the code again?\n";
        cout << "Press Y/y for yes and press N/n for no..\n";
        cin >> choice;
        
    } while(tolower(choice) == 'y');  // Continue if the user enters 'y' or 'Y'
    
    return 0;
}


