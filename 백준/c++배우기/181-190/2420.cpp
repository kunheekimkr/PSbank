#include<iostream>
using namespace std;
int main(){
    long long int n,m;
    cin >> n >> m;
    if(n-m<0)
        cout << m-n;
    else
        cout << n-m;
}