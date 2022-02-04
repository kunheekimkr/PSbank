#include<iostream>
using namespace std;
int a[42];
int main(){
    for(int i=0; i<10; i++){
        int n;
        cin >> n;
        a[n%42]++;
    }
    int cnt=0;
    for(int i=0; i<42; i++){
        if(a[i]!=0)
            cnt++;
    }
    cout << cnt;
}