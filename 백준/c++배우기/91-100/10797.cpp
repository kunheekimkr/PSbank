#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt=0;
    for( int i=1; i<=5; i++){
        int a;
        cin >> a;
        if (n ==a)
            cnt ++;
    }
    cout << cnt;
}