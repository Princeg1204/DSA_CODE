// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.

// Input: arr[] = [-1, -3, -10, 0, 6]
// Output: 30
// Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.

// Input: arr[] = [2, 3, 4] 
// Output: 24 
// Explanation: For an array with all positive elements, the result is product of all elements. 

// [Naive Approach] Using Two Nested Loops – O(n^2) Time and O(1) Space

#include <iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int> &arr) {

    int n = arr.size();
    int maxProd = arr[0];

    for (int i = 0; i < n; i++) {
        int mul = 1;
        for (int j = i; j < n; j++) {
          	mul *= arr[j];
            maxProd = max(maxProd, mul);
        }
    }
    return maxProd;
}

int main() {
    
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}


// [Expected Approach - 1] Track of Min and Max - O(n) Time and O(1) Space

#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &arr) {

  	int n = arr.size();
    int currMax = arr[0];
    int currMin = arr[0];
    int maxProd = arr[0];
    for (int i = 1; i < n; i++) {
        int temp = max({ arr[i], arr[i] * currMax,
                        					arr[i] * currMin });
      	currMin = min({ arr[i], arr[i] * currMax,
                    						arr[i] * currMin });
        currMax = temp;
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}