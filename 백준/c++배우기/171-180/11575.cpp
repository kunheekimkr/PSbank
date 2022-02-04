#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            s[i] =((s[i]-'A')*a+b)%26+'A';
        }
        cout << s << '\n';
    }
}