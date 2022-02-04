#include<iostream>
#include<string>
using namespace std;
int main(){
    long long int n;
    int b;
    string s;
    cin >> n >> b;
    while(n>0){
        int temp =n%b;
        char c;
        if(temp < 10)
            c= (temp+'0');
        else
            c= (temp+'A'-10);
        s+=c;
        n/=b;
    }
    for (int i=s.size()-1; i>=0; i--)
        cout << s[i];
}