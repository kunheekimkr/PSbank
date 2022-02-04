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

    for(int i=0; binarystring.size()%6!=0;i++){
        binarystring += '0';
    } //6자리씩 끊을 수 있도록 padding

    string encoding;
    for(int i=0; i<binarystring.size()/6;i++){
        string temp= binarystring.substr(i*6,6);
        int a=stoi(temp,0,2);
        char c;
        if(a<=25)
            c='A'+a;
        else if (a <=51)
            c= a+ 'a'- 26;
        else if ( a <= 61)
            c= a+ '0' -52;
        else if ( a==62)
            c= '+';
        else
            c= '/';
        encoding+=c;
    } // Encoding;
    
    for(int i=0; encoding.size()%4!=0;i++){
        encoding += '=';
    } //= padding
    cout << encoding;
}