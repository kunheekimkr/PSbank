#include<iostream>
using namespace std;
long long int dp[91][2]={0,};// 길이 n, 마지막 자리가 a 인 이친수의 개수 dp[n][a]
int main(){
    dp[1][1]=1;

    int n;
    cin >>n;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    
    cout << dp[n][0]+dp[n][1];
}