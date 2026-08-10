// Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
// Output: [1, 2]
// Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).

// Input: arr[] = [-5, 3, -5]
// Output: [-5]
// Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).

// Input: arr[] = [3, 2, 2, 4, 1, 4]
// Output: [ ]
// Explanation: There is no majority element.

// Brute force approach: O(n^2) time complexity and O(1) space complexity

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == arr[i])
                cnt += 1;
        }
      
        if (cnt > (n / 3)) {        
            if (res.size() == 0 || arr[i] != res[0]) {
                res.push_back(arr[i]);
            }
        }
        if (res.size() == 2) {
            if(res[0] > res[1])
                swap(res[0], res[1]);
            break;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}


// Optimal approach: O(n) time complexity and O(1) space complexity

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

    for (int ele : arr) {
        if (ele1 == ele) {
            cnt1++;
        }
      
        else if (ele2 == ele) {
            cnt2++;
        }
      
        else if (cnt1 == 0) {
            ele1 = ele;
            cnt1++;
        }
      
        else if (cnt2 == 0) {
            ele2 = ele;
            cnt2++;
        }

        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> res;
    cnt1 = 0;
    cnt2 = 0;

    for (int ele : arr) {
        if (ele1 == ele) cnt1++;
        if (ele2 == ele) cnt2++;
    }

    if (cnt1 > n / 3) res.push_back(ele1);
    if (cnt2 > n / 3 && ele1 != ele2) res.push_back(ele2);
    
    if(res.size() == 2 && res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}

int main() {
  
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (int ele : res) {
        cout << ele << " ";
    }
    return 0;
}