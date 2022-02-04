#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool comp(string s1, string s2){
    if(s1.size() !=s2.size())
        return s1.size() < s2.size();
    else
        return s1 < s2;
}
int main(){
    int n;
    cin >>n ;
    string s[n];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    sort(s,s+n,comp);
    for(int i=0;i<n;i++){
        if(s[i]!=s[i+1])
            cout << s[i] << '\n';
    }
}