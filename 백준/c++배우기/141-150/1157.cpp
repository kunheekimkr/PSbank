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
        if(s[i] >='a' && s[i] <= 'z')
            arr[s[i]-'a']++;
        else
            arr[s[i]-'A']++;
    }
    int max=0;
    int temp;
    for(int i=0; i<26;i++){
        if(arr[i]>max){
            max=arr[i];
            temp=i;
        }
    }
    int cnt=0;
    for(int i=0; i<26;i++){
        if(arr[i]==max){
            cnt++;
        }
    }
    if(cnt>1)
        cout << '?';
    else
        cout << char(temp + 'A');
}