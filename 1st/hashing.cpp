#include<bits/stdc++.h>
using namespace std;

// int main(){
//     string s;
//     cin >> s;
//     // pre compute the hash values for the string
//     int hash[26] = {0};
//     for(int i=0; i<s.size(); i++){
//         hash[s[i] - 'a']++;
//     }
//     int q;
//     cin >> q;
//     while(q--){
//         char c;
//         cin >> c;
//         //fetch the hash value for the character c and print it
//         cout << hash[c - 'a'] << endl;
//     }
//     return 0;
// }

int main(){
    string s;
    cin >> s;
    // pre compute the hash values for the string
    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }
    
    for(int i=0; i<256; i++){
        if(hash[i] > 0){
            cout << (char)i << "-->" << hash[i] << endl;
        }
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        //fetch the hash value for the character c and print it
        cout << hash[c] << endl;
    }
    return 0;
}