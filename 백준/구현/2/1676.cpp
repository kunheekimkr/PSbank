#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int result=0;
    while(n){
        result+=n/5;
        n/=5;
    }
    cout << result;
}