#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 1, 2};
    int n = 6;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for (auto x : freq) {
        cout << x.first << " -> " << x.second << endl;
    }

    return 0;
}
