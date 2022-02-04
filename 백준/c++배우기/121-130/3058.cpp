#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int sum=0;
        int arr[7];
        int min=101;
        for(int i=0; i<7; i++){
            int n;
            cin >> n;
            if(n%2==0){
                sum+=n;
                if( n < min)
                    min=n;
            }
        }
        cout << sum << ' ' << min << endl;
    }
}