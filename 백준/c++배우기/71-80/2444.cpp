#include<iostream>
using namespace std;
int main(){ 
    int n;
    cin >> n;
    for( int i=1; i<=n;i++){
        int space=n-i;
        while(space--){
            cout<<' ';
        }
        int star=2*i-1;
        while(star--){
            cout<<'*';
        }
        cout<<endl;
    }
    for( int i=n-1; i>=1;i--){
        int space=n-i;
        while(space--){
            cout<<' ';
        }
        int star=2*i-1;
        while(star--){
            cout<<'*';
        }
        cout<<endl;
    }
}