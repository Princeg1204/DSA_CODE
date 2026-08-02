#include<bits/stdc++.h>
using namespace std;

// Brute force

vector <int> UnionSortedArrays(vector<int> a, vector <int> b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for (int i=0; i<n1; i++) {
        st.insert(a[i]);
    } 
    for(int i=0; i<n2; i++) {
        st.insert(b[i]);
      }
      vector<int> temp;
      for(auto it : st) {
        temp.push_back(it);
      }
      return temp;   
    
}

// Optimal Approach

vector<int> UnionSortedArrays(vector<int> a, vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> temp;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            temp.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]) {
            temp.push_back(b[j]);
            j++;
        }
        else {
            temp.push_back(a[i]);
            i++;
            j++;
        }
    }
    while(i < n1) {
        temp.push_back(a[i]);
        i++;
    }
    while(j < n2) {
        temp.push_back(b[j]);
        j++;
    }
    return temp;
}