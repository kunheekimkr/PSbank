#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j-i<n-1; j++){
            if( i+j==n+1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "*" << endl;
    }
}