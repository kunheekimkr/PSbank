#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        cout << a*b/gcd(a,b) << '\n';
    }
}