#include<iostream>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    while(n--){
        int a;
        cin >> a;
        if( a<x )
            cout << a << ' ';
    }
}