#include<iostream>
using namespace std;
long long int dp[10001]={0,}; //앞선 연속한 i개가 포함되고 n번째를 포함할때 최대값 dp[i][n];
long long int max(long long int a, long long int b, long long int c){
    if(a>b){
        if(a>c)
            return a;
        else
            return c;
    }
    else{
        if(b<c)
            return c;
        else
            return b;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    for(int i=3; i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]);
    }

    cout << dp[n];
}