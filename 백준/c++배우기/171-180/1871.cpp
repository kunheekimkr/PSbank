#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int front, back;
        front=(int) (s[0]-'A') *26*26 +(int) (s[1]-'A')*26 + (int) (s[2]-'A');
        back=(int) (s[4]-'0') *1000 + (int) (s[5]-'0')*100 + (int) (s[6]-'0')*10 + (int) (s[7]-'0');
        if(front-back >=-100 && front-back <=100 )
            cout << "nice" << '\n';
        else
            cout << "not nice" << '\n'; 
    }
}