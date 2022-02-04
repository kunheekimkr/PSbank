#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string buf;
    getline(cin, buf);
    for(int i=1; i<=n; i++){
        string s;
        getline(cin, s);
        cout << i << ". " << s << endl;
    }
}