#include<iostream>
using namespace std;
long long int dp[2][100000];// a 행 b열의 스티커를 포함하는 조합의 최댓값 dp[a][b];
long long int max(long long int a, long long int b){
    if(a>=b)
        return a;
    else
        return b;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[2][n+1];
        for(int i=1; i<=n;i++)
            cin >> arr[0][i];
        for(int i=1;i<=n; i++)
            cin >> arr[1][i];

        dp[0][1]=arr[0][1];
        dp[1][1]=arr[1][1];
        dp[0][2]=arr[1][1]+arr[0][2];
        dp[1][2]=arr[0][1]+arr[1][2];
        for(int i=3; i<=n; i++){
            dp[0][i]=arr[0][i]+max(dp[1][i-1],dp[1][i-2]);
            dp[1][i]=arr[1][i]+max(dp[0][i-1],dp[0][i-2]);
        }
   
        cout << max(dp[0][n],dp[1][n]) << '\n';
    }
}