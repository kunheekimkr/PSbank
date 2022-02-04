#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int arr[26];
    for(int i=0; i<26; i++){
        arr[i]=-1;
    }
    for(int i=s.size()-1; i>=0; i--){
        arr[s[i]-'a']=i;
    }
    for(int i=0; i<26; i++){
        cout << arr[i] << ' ';
    }
}