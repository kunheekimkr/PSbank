#include<iostream>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char a='z';
        for(int i=0; i<s.size(); i++){
            if(char(s[i])<a)
                a=s[i];
        }
        string b="";
        int i;
        for(i=0; i<s.size(); i++){
            if(char(s[i])==a)
                break;
            b+=s[i];
        }
        for(i+=1; i<s.size();i++){
            b+=s[i];
        }
        cout << a << ' ' << b << endl;
    }
}