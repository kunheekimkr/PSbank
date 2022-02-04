#include<iostream>
#include<string>
using namespace std;
int main(){
    string s[6];
    int cnt=0;
    for(int n=1; n<=5; n++){
        cin >> s[n];
    }
    for(int n=1; n<=5; n++){
        if(s[n].find("FBI") != string::npos){
            cout << n << ' ';
            cnt++;
        }
    }
    if(cnt==0){
        cout << "HE GOT AWAY!";
    }
}