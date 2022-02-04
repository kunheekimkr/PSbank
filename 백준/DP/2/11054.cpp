#include<iostream>
using namespace std;
int dpa[1001]={0, }; // n번째 수로 끝나는 가장 긴 감소하는 부분수열 dpa[n];
int dpd[1001]={0, }; // n번째 수부터 시작하는 가장 긴 감소하는 부분수열 dpd[n];
int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dpa[1]=1;
    for(int i=2;i<=n;i++){
        int maxa=0;
        for(int j=1;j<i;j++){
            if(arr[j] < arr[i]){
                if(dpa[j]>maxa)
                    maxa=dpa[j];  // 가장 큰 수가 i 번째 수 보다 작은 가장 긴 증가하는 부분 수열 을 maxa에 저장  
            }
        }
        dpa[i]=maxa+1;
    }//1부터 i번째 수 중 i로 끝나는 가장 긴 증가수열 계산

    dpd[n]=1;
    for(int i=n-1; i>0; i--){
        int maxd=0;
        for(int j=n;j>i;j--){
            if(arr[j] < arr[i]){
                if(dpd[j]>maxd)
                    maxd=dpd[j];  
            }
        }
        dpd[i]=maxd+1;

    }// 역으로 i부터 n번째 수 중 i로 시작하는 가장 긴 감소수열 계산
    
    int max=0;
    for(int i=1; i<=n;i++){
        if (dpa[i]+dpd[i]-1>max)//i가 최대값인 가장 긴 바이토닉 수열 = dpa[i] + dpd[i] -1
            max=dpa[i]+dpd[i]-1;
    }
    cout << max;
}