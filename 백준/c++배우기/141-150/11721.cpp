#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.size()/10; i++){
        for(int j=0; j<10; j++){
            cout << s[i*10 +j];
        }
        cout << endl;
    }
    for(int i=0; i<s.size()%10; i++){
        cout << s[s.size()-s.size()%10+i];
    }
}
