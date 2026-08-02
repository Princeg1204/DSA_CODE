#include<bits/stdc++.h>
using namespace std;
void print1(int n )
{
    for(int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n-i+1; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void print2(int n )
{
    for(int i = 0; i<=n; i++)
    {
        for (int j = 0; j<n-i-1; j++)
        {
            cout << " ";
        }
        for(int j = 0; j<2*i+1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j<n-i-1; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void print3(int n )
{
    for(int i = 0; i<=n; i++)
    {
        for (int j = 0; j<i; j++)
        {
            cout << " ";
        }
        for(int j = 0; j< 2*n - (2*i+1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j<i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void print4(int n)
{
    for(int i = 1; i<= 2*n-1; i++)
    {
        int starts = i;
        if (i>n) starts = 2*n - i;
        for (int j = 1; j <= starts; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print5(int n )
{
    int starts = 2 * n - 2;
    for (int i = 1; i <=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            cout << j;
        }
        for (int j=1; j<=starts; j++)
        {
            cout << " ";
        }
        for (int j=i; j>=1; j--)
        {
            cout << j;
        }
        starts -= 2;
        cout << endl;
    }
}
void print6(int n )
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i+1; j++)
        {
            cout << num << " " ; 
            num++;
        }
        cout << endl;
    }
}
int main()
{
    print6(5);
    return 0;
}