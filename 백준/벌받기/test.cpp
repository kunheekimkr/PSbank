#include<iostream>
#include<string>
#include<bitset>
using namespace std;
int main(){
    string s;
    cin >> s;
    string binarystring;
    for(int i=0; i<s.size(); i++){
        binarystring += bitset<8>(s[i]).to_string();
    } //문자열을 2진법으로 전환
    cout << binarystring;
}