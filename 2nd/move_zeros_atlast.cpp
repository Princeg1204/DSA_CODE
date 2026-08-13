// Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
// Output: [1, 2, 4, 3, 5, 0, 0, 0]
// Explanation: There are three 0s that are moved to the end.

// Input: arr[] = [10, 20, 30]
// Output: [10, 20, 30]
// Explanation: No change in array as there are no 0s.

// Input: arr[] = [0, 0]
// Output: [0, 0]
// Explanation: No change in array as there are all 0s.


#include<bits/stdc++.h>
using namespace std;

//  Brute force
vector<int> moveZerosToEnd(int n, vector<int> arr) {
    
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    int nz = temp.size();
    for(int i = 0; i < nz; i++) {
        arr[i] = temp[i];
    }

    for(int i = nz; i < n; i++) {
        arr[i] = 0;
    }
    return arr;
}

// Optimal Approach

vector<int> moveZerosToEndOptimal(int n, vector<int> arr) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j=i;
            break;
        }
    }
    if(j==-1) return arr;

    for (int i=j+1; i<n; i++){
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}
