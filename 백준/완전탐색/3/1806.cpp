#include<iostream>
using namespace std;
int n,m;
int a[100000];
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
    int min=n+1;

    while (true){     
        if (end >= n)
            break;

        if(sum >= m){
            if(end-start+1 < min)
                min =end-start+1;
        }

        if(sum <= m){ 
            end++;
            sum+=a[end];
        }
        else{ 
            sum-=a[start];
            start++;
        }
    }

    if (min == n+1) //합을 만드는것이 불가능한 경우
        min=0;
    cout << min;
}