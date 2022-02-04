#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+int(s[i])-'1'+1;
    }
    cout << sum;
}