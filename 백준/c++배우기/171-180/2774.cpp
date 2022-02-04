#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int arr[10];
        for(int i=0;i<10;i++){
            arr[i]=0;
        }
        int n;
        cin >> n;
        while(n){
            arr[n%10]++;
            n/=10;
        }
        int cnt=0;
        for(int i=0;i<10;i++){
            if(arr[i]!=0)
                cnt++;
        }
        cout << cnt << '\n';
    }
}