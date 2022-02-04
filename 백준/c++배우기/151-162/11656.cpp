#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    string arr[1000];
    for(int i=0;i<s.size();i++){
        arr[i]=s.substr(i,s.size()-i);
    }
    sort(arr, arr+s.size());
    for(int i=0;i<s.size();i++){
        cout << arr[i] << '\n';
    }
}