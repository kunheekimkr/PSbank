#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int p[n+1]={0,};
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    int dp[n+1]={0,}; //n개 카드를 사는 가격의 최댓값 dp[n]
    dp[1]=p[1];
    for(int i=2; i<=n; i++){
        int max=0;
        for(int k=1; k<=i; k++){
            if(max< dp[i-k]+p[k])
                max= dp[i-k]+p[k];
        }
        dp[i]=max;
    }
    cout << dp[n];
}