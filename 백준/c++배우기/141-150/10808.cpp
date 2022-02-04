#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int arr[26];
    for(int i=0; i<26; i++){
        arr[i]=0;
    }
    for(int i=0; i<s.size(); i++){
        arr[s[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        cout << arr[i] << ' ';
    }
}