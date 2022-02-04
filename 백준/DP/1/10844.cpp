#include<iostream>
using namespace std;
int dp[101][10];// 길이 n, 마지막 자리가 a 인 계단수의 개수 dp[n][a]
int main(){
    dp[1][0]=0;
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }

    int n;
    cin >>n;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1];
        for(int j=1;j<=8;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
        }
        dp[i][9]=dp[i-1][8];
    }
    
    int sum=0;
    for(int i=0;i<10;i++){
        sum=(sum+dp[n][i])%1000000000;
    }
    cout << sum;
}