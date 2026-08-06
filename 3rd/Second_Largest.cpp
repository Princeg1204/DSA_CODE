#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force approach
int getSecondLargest(vector<int> &arr) {
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
  
    for (int i = n - 2; i >= 0; i--) {
      
        if (arr[i] != arr[n - 1]) {
            return arr[i];
        }
    }
  
    return -1;
}

int main() {
    vector<int> arr = { 12, 35, 1, 10, 34, 1 };
    cout<<getSecondLargest(arr);
    return 0;
}



// Better approach

#include <iostream>
#include <vector>
using namespace std;
int getSecondLargest(vector<int> &arr) {
    int n = arr.size();

    int largest = -1, secondLargest = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << getSecondLargest(arr);

    return 0;
}



// Optimized approach

#include <iostream>
#include <vector>
using namespace std;
int getSecondLargest(vector<int> &arr) {
    int n = arr.size();

    int largest = -1, secondLargest = -1;

    for (int i = 0; i < n; i++) {
        if(arr[i] > largest) {
        	secondLargest = largest;
            largest = arr[i];
        }
        
      	else if(arr[i] < largest && arr[i] > secondLargest) {
        	secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << getSecondLargest(arr);

    return 0;
}