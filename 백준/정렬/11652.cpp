#include<iostream>
#include<algorithm>
using namespace std;
long long arr[1000000]={0,};
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+n);

    int max=0;
    int index=0;
    int cnt=1;    
    for(int i=0; i<n-1; i++){

        if(arr[i]==arr[i+1]){
            cnt++;
            if(cnt>max){
                max=cnt;
                index=i;
            }
        }
        else{
            cnt=1;
        }
    }
    cout << arr[index];
}