#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for(int i=0; i<m ;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int sum[m][n]={0,};
    for(int i=0; i<m ;i++){
        for(int j=0;j<n;j++){
            if( i==0 && j==0)
                sum[i][j] = arr[i][j];
            else if (i==0)
                sum[i][j] = sum[i][j-1] + arr[i][j];
            else if (j==0)
                sum[i][j] = sum[i-1][j] + arr[i][j];
            else{
                sum[i][j] = arr[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
            }
        }
    }
    int cnt=0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
                for(int k=i; k>=0; k--){
                    int result=0;
                    for(int l=j; l>=0;l--){
                        if(k==0 && l==0){
                            result =sum[i][j];
                            if(result == 10){
                                cnt++;
                                break;   
                            }
                        }
                        else if (k==0){
                            result=sum[i][j]-sum[i][l-1];
                            if(result==10){
                                cnt++;
                                break;
                            }
                        }
                        else if (l==0){
                            result=sum[i][j] -sum[k-1][j];
                            if(result ==10){
                                cnt++;
                                break;
                            }
                        }
                        else{
                            result=sum[i][j] - sum[i][l-1] -sum[k-1][j] +sum[k-1][l-1];
                            if(result ==10){
                                cnt++;
                                break;
                            }
                        }
                    }
                }
        }
    }
    cout << cnt;
}