#include<iostream>
#include<string>
using namespace std;
long long gcd(long long a, long long b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    long long a,b;
    cin >> a >> b;
    long long g=gcd(a,b);
    while(g--){
        cout << '1';
    }   
}