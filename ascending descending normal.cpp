// PROGRAM TO SORT AN ARRAY OF NUMBER AN ASCENDING AND DEECENDING ORDER.WRITE COEDS FOR USER DEFINED FUNCTION.
#include <iostream>
using namespace std;

// Function to sort array in ascending order
void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Function to sort array in descending order
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int n,si;
    while(true){
    	cout<<"Enter a serial number:"<<endl;
    	cin>>si;
    	if(si==0)break;


    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to sort in ascending order
    sortAscending(arr, n);
    cout << "Array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
  // Call the function to sort in descending order
    sortDescending(arr, n);
    cout << "Array in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    	}
  return 0;
}

