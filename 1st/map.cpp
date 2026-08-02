#include<bits/stdc++.h>
using namespace std;
int main()
{
    // 7
    int n ;
    cin >> n;

    // 2 3 4 3 4 2 3
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    map<int, int>mpp;
    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
    }
    
    for(auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }

    int q;
    cin >> q;
    while(q--)
    {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }
    return 0;
}
