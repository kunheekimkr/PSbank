#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    string s=to_string(n);
    int cnt=0;
    if(s.size()*n <=m){
        for(int i=0; i<n; i++)
            cout << s;
    }
    else {
        for(int i=0; i<m/s.size(); i++){
            cout << s;
        }
        for(int i=0; i<m%s.size();i++){
            cout << s[i];
        }
    }
}