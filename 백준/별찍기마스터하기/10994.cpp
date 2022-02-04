#include<iostream>
using namespace std;
char arr[397][397];
void star(int n, int row, int column){
    for(int i=0; i< 4*n-3; i++){
        if(i==0 || i==4*n-4){
            for (int j=0; j< 4*n-3; j++){
            arr[row+i][column+j]='*';
            }
        }
        else{
            arr[row+i][column]='*';
            arr[row+i][column+4*n-4]='*';
        }
    }

    if(n>1){
            star(n-1,row+2,row+2);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<=4*n-3;i++){
        for(int j=0; j<=4*n-3; j++){
            arr[i][j]=' ';
        }
    }

    star(n,0,0);

    for(int i=0; i<4*n-3;i++){
        for(int j=0; j<4*n-3; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}