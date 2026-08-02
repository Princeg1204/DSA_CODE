#include <iostream>
#include <vector>
using namespace std;

int kthMissing(vector<int>& arr, int k) {
    int current = 1;
    int i = 0;

    while (true) {

        // Number exists in array
        if (i < arr.size() && arr[i] == current) {
            i++;
        }
        else {
            k--;

            if (k == 0)
                return current;
        }

        current++;
    }
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << kthMissing(arr, k);

    return 0;
}