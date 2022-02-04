#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z')
                cout << (char) (s[i]-'A'+'a');
            else
                cout << s[i];
        }
        cout << '\n';
    }

}