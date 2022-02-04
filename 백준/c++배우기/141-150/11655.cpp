#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    for(int i=0; i<=s.size();i++){
        if(s[i]>='A' && s[i] <='Z'){
            s[i]+=13;
            if(s[i]>'Z')
                s[i]=s[i]-'Z'+'A'-1;
        }
        // char는 128까지만 저장되므로 나눠서 계산
        else if(s[i]>='a' && s[i] <='m'){
            s[i]+=13;
        }
        else if(s[i]>='n' && s[i] <='z'){
            s[i]=s[i]-'z'+'a'+12;
        }
    }
    cout << s;
}