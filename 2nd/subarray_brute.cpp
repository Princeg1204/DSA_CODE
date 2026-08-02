#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 1, 1, 2, 1, 1, 1, 4, 2};
    int n = arr.size();
    int k = 3; // Target sum
    for(int i = 0; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int sum = 0; 
            int len = 0;
            for(int k = i; k < j; k++)
            {
                cout << arr[k] << " ";
                sum += arr[k];  
                if(sum == k)
                {
                    len = max(len, j - i + 1);
                }
            }
            cout << "Sum: " << sum << ", Length: " << len << endl;
        }
    }
}