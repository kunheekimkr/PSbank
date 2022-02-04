#include<iostream>
using namespace std;
int n,m;
int a[10000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    int start=0;
    int sum=a[0];
    int end=0;
    int cnt=0;

    while (true){ //투 포인터 알고리즘
        if (end >= n)
            break;
        if(sum == m)
            cnt++;
        if(sum <= m){ //start부터 end까지의 합이 m보다 클 경우 end를 늘림
            end++;
            sum+=a[end];
        }
        else{ //start부터 end까지의 합이 m보다 작을 경우 start를 늘림
            sum-=a[start];
            start++;
        }
    }
    cout << cnt;
}