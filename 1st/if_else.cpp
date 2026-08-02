#include<bits/stdc++.h>
using namespace std;
int main(){
    int age;
    cin >> age;
    if(age >= 18){
        cout << "You are an adult." << endl;
    }
    else if(age >= 13 && age < 18){
        cout << "You are not an adult." << endl;
    }
    return 0;
}