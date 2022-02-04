#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n-1; i++){
        cout << " ";
        for(int j=1; j-i<n-2; j++){
            if( i+j==n)
                cout << "*";
            else
                cout << " ";
        }
        cout << "*" << endl;
    }
    for(int i=1; i<=2*n-1;i++)
        cout << "*";
}