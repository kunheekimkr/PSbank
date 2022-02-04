#include<iostream>
using namespace std;

int dom[1000];
int domino(int n){
    if(n==0)
        return 0;
    if(dom[n]!=0)
        return dom[n];
    else
        dom[n]=domino(n-1)+n*(n+1)*3/2;
        return dom[n];
}
int main(){
    int n;
    cin >> n;
    cout << domino(n);
}