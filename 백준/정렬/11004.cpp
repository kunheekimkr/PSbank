#include<iostream>
#include<algorithm>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    cout << arr[k-1];
}