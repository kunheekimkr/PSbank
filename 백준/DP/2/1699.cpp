#include<iostream>
using namespace std;
int min(int a,int b){
    if( a < b)
        return a;
    else 
        return b;
}

int main(){
    int n;
    cin >> n;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=i; // 최댓값= 모두 1로 더할 때
    }
    for(int i=2;i<=n;i++){
        for(int j=1; j*j <=i; j++){
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }

    cout << dp[n];
}