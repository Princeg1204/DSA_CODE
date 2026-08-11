// Input: arr[] = [1, 4, 3, 2, 6, 5]  
// Output:  [5, 6, 2, 3, 4, 1]
// Explanation: The first element 1 moves to last position, the second element 4 moves to second-last and so on.

// Input: arr[] = [4, 5, 1, 2]
// Output: [2, 1, 5, 4]
// Explanation: The first element 4 moves to last position, the second element 5 moves to second last and so on.

// [Naive Approach] Using a temporary array - O(n) Time and O(n) Space

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp(n);
    for(int i = 0; i < n; i++)
        temp[i] = arr[n - i - 1];
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}


// [Expected Approach - 1] Using Two Pointers - O(n) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr) {
  
    int left = 0, right = arr.size() - 1;
    while(left < right) {
      
        swap(arr[left], arr[right]);
      
        left++;
      
        right--;
    }
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}


// [Expected Approach - 2] Using Single Pointer - O(n) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n/2; i++) {
    	swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}


// Using Inbuilt Methods - O(n) Time and O(1) Space

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
void reverseArray(vector<int> &arr) {
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}
