#include<iostream>
using namespace std;
char arr[399][397];
void star(int n, int row, int column){
    for(int i=0; i<4*n-3; i++)
        arr[row][column-i]='*';
    for(int i=0; i<4*n-2;i++)
        arr[row+1+i][column-4*n+4]='*';
    for(int i=0; i<4*n-4;i++)
        arr[row+4*n-2][column-4*n+5+i]='*';
    for(int i=0; i< 4*n-3; i++)
        arr[row+4*n-2-i][column]='*';
    arr[row+2][column-1]='*';


    if(n>2){
        star(n-1,row+2,column-2);
    }

    else if (n==2){
        arr[row+2][column-2]='*';
        arr[row+3][column-2]='*';
        arr[row+4][column-2]='*';
    }
}

int main(){
    int n;
    cin >> n;
    if( n==1){
        cout << '*';
    }
    else{
        for(int i=0; i<4*n-1;i++)
            for(int j=0; j<4*n-3; j++)
                arr[i][j]=' ';

        star(n,0,4*n-4);


        for(int i=0; i<4*n-1;i++){
            if(i!=1){
                for(int j=0; j<4*n-3; j++)
                    cout << arr[i][j];
            }
        else
            cout << '*';
        cout << endl;
        }
    }

}