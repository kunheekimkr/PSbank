#include<iostream>
using namespace std;
int dp[1001]={0,}; // n번째 수로 끝나는 가장 긴 감소하는 부분수열 dp[n];
int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int max=0;
        for(int j=1;j<i;j++){
            if(arr[j] > arr[i]){
                if(dp[j]>max)
                    max=dp[j];  // 가장 작은 수가 i 번째 수 보다 큰 가장 긴 감소하는 부분 수열 을 max에 저장  
            }
        }
        dp[i]=max+1;
    }

    int max=0;
    for(int i=1; i<=n;i++){
        if (dp[i]>max)
            max=dp[i];
    }
    cout << max;
}