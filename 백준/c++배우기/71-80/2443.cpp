#include<iostream>
using namespace std;
int main(){ 
    int n;
    cin >> n;
    for( int i=n; i>=1;i--){
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