#include<iostream>
using namespace std;
int dp[1001][10]={0,};// 길이 n, 마지막 자리가 a 인 오르막 수의 개수 dp[n][a]
int main(){
    for(int i=0;i<10;i++){
        dp[1][i]=1;
    }

    int n;
    cin >>n;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            for(int k=0; k<=j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%10007;
            }
        }
    }
    
    int sum=0;
    for(int i=0;i<10;i++){
        sum=(sum+dp[n][i])%10007;
    }
    cout << sum;
}