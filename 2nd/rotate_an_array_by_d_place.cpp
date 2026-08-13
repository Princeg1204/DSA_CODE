// Input: arr[] = [1, 2, 3, 4, 5, 6], d = 2
// Output: [3, 4, 5, 6, 1, 2]
// Explanation: After first left rotation, arr[] becomes [2, 3, 4, 5, 6, 1] and after the second rotation, arr[] becomes [3, 4, 5, 6, 1, 2]

// Input: arr[] = [1, 2, 3], d = 4
// Output: [2, 3, 1]
// Explanation: The array is rotated as follows:

// After first left rotation, arr[] = [2, 3, 1]
// After second left rotation, arr[] = [3, 1, 2]
// After third left rotation, arr[] = [1, 2, 3]
// After fourth left rotation, arr[] = [2, 3, 1]


// Brute force approach Rotate One by One - O(n * d) Time and O(1) Space

#include <bits/stdc++.h>
using namespace std;

void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
  
    for (int i = 0; i < d; i++) {
      
        int first = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = first;
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;

    rotateArr(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}

// Better approach Using Temporary Array - O(n) Time and O(n) Space

#include <bits/stdc++.h>
using namespace std;
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    d %= n;
    vector<int> temp(n);

    for (int i = 0; i < n - d; i++)
        temp[i] = arr[d + i];

    for (int i = 0; i < d; i++)
        temp[n - d + i] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;

    rotateArr(arr, d);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}

// Optimal Approach Reversal Algorithm - O(n) Time and O(1) Space

#include <bits/stdc++.h>

using namespace std;
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
  
    d %= n;
  
    reverse(arr.begin(), arr.begin() + d);

    reverse(arr.begin() + d, arr.end());
  
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;
    
  	rotateArr(arr, d);
  
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}
