#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int dp[n]; //n번째 수를 포함하는 최대 연속합
    dp[0]=arr[0];
    for(int i=1; i<n; i++){
        if(dp[i-1]<0)
            dp[i]=arr[i];
        else
            dp[i]=dp[i-1]+arr[i];
    }
    int max=dp[0];
    for(int i=1; i<n; i++){
        if(dp[i]>max)
            max=dp[i];
    }
    cout << max;

}