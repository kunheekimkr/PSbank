#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    for(int i=0; i<s[0].size();i++){
        int cnt=0;
        for(int j=0; j<n-1;j++){
            if (s[j][i]!=s[j+1][i]){
                cnt++;
                break;
            }
        }
        if(cnt==0)
            cout << s[0][i];
        else
            cout << '?';
    }
}