#include<iostream>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n+1][n]={0,};
        for(int i=0; i<n; i++){
            cin >> arr[0][i];
        }
        for(int i=1; i<n+1;i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(arr[i-1][k] == arr[i-1][j])
                        arr[i][j]++;
                }
            }
        }

        int q;
        cin >> q;
        while(q--){
            int x;
            int k;
            cin >> x >> k;
            if( k < n+1)
                cout << arr[k][x-1] << '\n';
            else
                cout << arr[n][x-1] << '\n';
        }       
    }
}