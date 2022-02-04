#include<iostream>
using namespace std;
char arr[3072][6143];
void star(int n, int row, int column){
    if( n==3){
        for(int i=0; i<=2; i++){
            for(int j=0; j<=i; j++){
                if( i!=1 || j!=0 ){
                    arr[row+i][column+j]='*';
                    arr[row+i][column-j]='*';
                }
            }
        }
    }
    else{
        star( n/2 ,row ,column);
        star( n/2, row+n/2, column-n/2);
        star( n/2, row+n/2, column+n/2);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n;i++)
        for(int j=0; j<2*n-1; j++)
            arr[i][j]=' ';

    star(n,0,n-1);

    for(int i=0; i<n;i++){
        for(int j=0; j<2*n-1; j++)
            cout << arr[i][j];
        cout << endl;
    }

}