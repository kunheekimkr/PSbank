#include<iostream>
#include<string>
using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << stoll(to_string(a)+to_string(b)) + stoll(to_string(c)+to_string(d));
}