#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    string fs;
    while(s.size()%3!=0){
        s='0'+s;
    }
    for(int i=0; i<s.size()/3; i++){
        int temp=s[i*3+2]-'0' + 2*(s[i*3+1]-'0') + 4*(s[i*3]-'0');
        cout<< temp;
    }
}