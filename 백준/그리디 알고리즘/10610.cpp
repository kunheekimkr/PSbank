#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool compare(int a, int b){
    return a>b;
}
int main(){
    vector<int>v;
    string s;
    cin >> s;
    for(int i=0; i<s.size();i++)
        v.push_back(s[i]-'0');
    sort(v.begin(),v.end(),compare);
    int sum=0;
    int cnt=0;
    for(int i=0;i <s.size();i++){
        sum+=v[i];
        if(v[i]==0)
            cnt++;
    }
    if(sum%3==0 && cnt !=0){
        for(int i=0; i<s.size();i++)
            cout <<v[i];
    }
    else
        cout << -1;
}