#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[101];
    for (int i=1; i<101;i++){
        arr[i]=0;
    }
    int cnt=0;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        if(arr[a]>0)
            cnt++;
        arr[a]++;
    }
    cout << cnt;
}