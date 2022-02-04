#include<iostream>
#include<string>

using namespace std;
int main(){
    string s;
    cin >> s;
    int i= s.size();
    for(int j=0; j<i; j++){
        int a= (int) s[j];
        cout << hex << uppercase << a;
    }
}