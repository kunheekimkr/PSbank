#include<iostream>
using namespace std;

long long int dp[1001][3]={0,};

long long int min(long long int a,long long int b){
    if(a>b)
        return b;
    else
        return a;
}

int main(){
    int n;
    cin >> n;
    int arr[n+1][3];
    for(int i=1; i<=n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    
    dp[1][0]=arr[1][0];
    dp[1][1]=arr[1][1];
    dp[1][2]=arr[1][2];

    for(int i=2; i<=n;i++){
        dp[i][0]=min(dp[i-1][1], dp[i-1][2])+arr[i][0];
        dp[i][1]=min(dp[i-1][0], dp[i-1][2])+arr[i][1];
        dp[i][2]=min(dp[i-1][0], dp[i-1][1])+arr[i][2];
    }

    cout << min(min(dp[n][0],dp[n][1]),dp[n][2]);
}