#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    if (s.compare("0") == 0){
        cout << 0;
    }
    else{
        int temp=s[0]-'0';
        if( temp >=4)
            cout << temp/4 << (temp%4)/2 << (temp)%2;
        else if (temp >=2)
            cout << temp/2 << temp %2;
        else
            cout << temp;

        for(int i=1; i<s.size();i++){
            int temp=s[i]-'0';
            cout << temp/4 << (temp%4)/2 << (temp)%2;
        }
    }
}