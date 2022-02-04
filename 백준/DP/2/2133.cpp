#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n+1]; // 3xN 벽을 채우는 경우의 수
    int b[n+1]; // 3XN 벽에 2X1 타일을 한개 채운 ㄱ자형 벽을 채우는 경우의 수

    a[0]=0;
    a[1]=0;
    a[2]=3;
    b[0]=0;
    b[1]=0;
    b[2]=1;
    for(int i=3; i<=n; i++){
        b[i]=a[i-2]+b[i-2];
        a[i]=2*a[i-2]+b[i]+b[i-2];
    }
    cout << a[n];
}
