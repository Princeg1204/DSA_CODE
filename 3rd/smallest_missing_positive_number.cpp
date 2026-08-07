// Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: 3 is the smallest positive number missing from the array.

// Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: 4 is the smallest positive number missing from the array.

// Brute Force Approach: By Sorting - O(n*log n) Time and O(1) Space

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int> &arr) {
    
    sort(arr.begin(), arr.end());
    int res = 1;
    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == res) 
            res++;

        else if (arr[i] > res) 
            break;
    }
    return res;
}

int main() {
    vector<int> arr = {2, -3, 4, 1, 1, 7};

    cout << missingNumber(arr);
    return 0;
}

// Better approach Using Visited Array - O(n) Time and O(n) Space

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr) {
    int n = arr.size();

    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {

        if (arr[i] > 0 && arr[i] <= n)
            vis[arr[i] - 1] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i - 1]) {
            return i;
        }
    }

    return n + 1;
}

int main() {

    vector<int> arr = {2, -3, 4, 1, 1, 7};
	cout << missingNumber(arr);
}

// Optimal Approach Using Cycle Sort - O(n) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        while (arr[i] >= 1 && arr[i] <= n
               && arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i != arr[i-1]) {
            return i;
        }
    }

    return n + 1;
}

int main() {
    
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr);
    return 0;
}