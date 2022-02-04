#include<iostream>
using namespace std;
long long int dp[201][201]={0,}; //k개의 수의 합으로 n을 표현하는 경우의 수 arr[k][n]
int main(){
    int n,k;
    cin >> n >> k;
    
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n;j++){
            if(i==1)
                dp[i][j]=1;
            else{
                for(int l=0; l<=j; l++){
                    dp[i][j]+=dp[i-1][l];
                    dp[i][j]%=1000000000;
                }
            }
        }
    }

    cout << dp[k][n];
}