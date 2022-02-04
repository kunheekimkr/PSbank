#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    if(str[0]== '0'){
        cout << '0'; //암호가 0으로 시작하면 오류
        return 0;
    }
    int dp[str.size()+1]={0,}; //n번째 자리까지 끊었을 때 해독 가능한 경우의 수 dp[n]
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=str.size(); i++){
        if(str[i-1]=='0' && str[i-2]=='0'){
            cout << 0;
            return 0;
        }
        if (str[i-1]!= '0')
            dp[i]+=dp[i-1]; // n번째 자리가 0이 아니면 따로 한 자리 수로 끊을 수 있음
        if (str[i-2]!= '0'){
            if(((str[i-2]-'0')*10+(str[i-1]-'0'))<=26){
                dp[i]+=dp[i-2]; // n-1번째 자리가 0이 아니면 n번째 자리와 함께 두 자리로 끊을 수도 있음
            }
        }
        dp[i]%=1000000;
    }
    
    cout << dp[str.size()];
}