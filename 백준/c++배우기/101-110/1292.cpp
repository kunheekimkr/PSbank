#include<iostream>
using namespace std;

int a[1001];
int main(){
    int temp=0;
    for(int i=1; i<=44;i++){
        for(int j=1; j<=i; j++){
            a[temp+j]=i;
        }
        temp+=i;
    }//1~980 배열 값 설정
    for(int i=991; i<1001; i++){
        a[i]=45;
    }//981-1000 배열 값 설정
    int min,max;
    cin >> min >> max;
    int sum=0;
    for(int i=min; i<=max ;i++){
        sum+=a[i];
    }
    cout << sum; 
}