#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=4*n-2-i;j++){
            if(i==1){
                if ((1<=j && j<= n)||(j>=3*n-2 && j<=4*n-2-i))
                    cout << '*';
                else
                    cout << ' ';
            }
            else{
                if(j==i || j==n+i-1 || j==3*n-1-i || j==4*n-2-i )
                    cout << '*';
                else
                    cout << ' ';
            }
        }
        cout << endl;
    }
    for(int i=n-1; i>=1;i--){
        for(int j=1; j<=4*n-2-i;j++){
            if(i==1){
                if ((1<=j && j<= n)||(j>=3*n-2 && j<=4*n-2-i))
                    cout << '*';
                else
                    cout << ' ';
            }
            else{
                if(j==i || j==n+i-1 || j==3*n-1-i || j==4*n-2-i )
                    cout << '*';
                else
                    cout << ' ';
            }
        }
        cout << endl;
    }
}