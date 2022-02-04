#include<iostream>
#include<algorithm>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n;
    cin >> n;

    int arr[10001]={0,};
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr[num]++;
    }
    
    for(int i=0; i<10001; i++){
        while(arr[i]--){
            cout << i << '\n';
        }
    }    
}