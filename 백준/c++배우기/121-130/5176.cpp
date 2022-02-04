#include<iostream>
using namespace std;
int main(){
    int k;
    cin >>k;
    while(k--){
        int p, m;
        cin >> p >> m;
        int arr[m+1];
        for(int i=0; i<m+1; i++){
            arr[i]=0;
        }
        for(int i=0; i<p; i++){
            int n;
            cin >>n;
            arr[n]++;
        }
        int cnt=0;
        for(int i=1; i<m+1; i++){
            if(arr[i]>1)
                cnt+=arr[i]-1;
        }
        cout << cnt << endl;
    }
}