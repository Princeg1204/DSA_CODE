// Input: arr[] = [2, 4, 1, 7, 5, 0]
// Output: [2, 4, 5, 0, 1, 7]
// Explanation: The next lexicographically greater arrangement of the elements in the array arr[] is [2, 4, 5, 0, 1, 7].

// Input: arr[] = [3, 2, 1]
// Output: [1, 2, 3]
// Explanation: This is the last permutation, so we return the lowest possible permutation (ascending order).

// Input: arr[] = [1, 3, 5, 4, 2]
// Output: [1, 4, 2, 3, 5]
// Explanation: The next lexicographically greater arrangement of the elements in the array arr[] is [1, 4, 2, 3, 5].


#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &arr) {
  
    int n = arr.size(); 

    int pivot = -1; 
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    reverse(arr.begin() + pivot + 1, arr.end());
}

int main() {
    
    vector<int> arr = { 2, 4, 1, 7, 5, 0 };
    nextPermutation(arr);    
    for (int x : arr) 
        cout << x << " ";    
    return 0;
}
