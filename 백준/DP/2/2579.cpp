#include<iostream>
using namespace std;

int max(int a, int b){
    if( a>b)
        return a;
    else
        return b;
}

int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    int dp1[n+1]; // n번째 계단과 n-1번쨰 계단을 밟았을 때의 최댓값 dp1[n];
    int dp2[n+1]; // n번째 계단을 밟고 n-1계단을 밟지 않았을 때의 최댓값 dp2[n];

    dp1[1]=arr[1];
    dp1[2]=arr[1]+arr[2];
    dp2[1]=arr[1];
    dp2[2]=arr[2];

    for(int i=3; i<=n; i++){
        dp1[i]=dp2[i-1]+arr[i];
        dp2[i]=max(dp1[i-2],dp2[i-2])+arr[i];
    }

    cout << max(dp1[n],dp2[n]);

}