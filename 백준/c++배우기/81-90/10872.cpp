#include<iostream>
using namespace std;
int ft[12];
int factorial(int n){
    if (n==0)
        return 1;
    if (ft[n]!=0)
        return ft[n];
    else
        ft[n]=factorial(n-1)*n;
    return ft[n];
}
int main(){
    int n;
    cin >> n;
    cout << factorial(n);
}