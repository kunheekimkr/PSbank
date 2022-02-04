#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a==0){
        return b;
    }
    else if (b==0){
        return a;
    }
    else if (a>=b){
        return gcd(a%b,b);
    }
    else if (a<b){
        return gcd(a, b%a);
    }
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cout<< lcm(a,b) << ' ' << gcd(a,b) << '\n';
    }
}