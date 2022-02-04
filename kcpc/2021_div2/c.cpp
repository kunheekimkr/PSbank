#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int mid=(n+1)/2;
    int ans=0;
    for(int i=0; i<mid; i++){
        ans = ans + (int)log2(arr[i]);
    }
    cout << ans+1;
}