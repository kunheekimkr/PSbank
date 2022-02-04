#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        long long sum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sum+=gcd(arr[i],arr[j]);
            }
        }
        cout << sum <<'\n';
    }
}