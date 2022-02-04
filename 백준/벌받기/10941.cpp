#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int i=s.size();
    for(int j=0; j<i/2 ; j++){
        int a=s[2*j];
        if( a < 65)
            a-=48;
        else
            a-=55;
        int b=s[2*j+1];
        if( b < 65)
            b-=48;
        else
            b-=55;
        char c=a*16+b;
        cout << c;
    }
}