#include<iostream>
using namespace std;
char arr[1023][2045];
int pow(int n){
    int a=1;
    while(n--){
        a*=2;
    }
    return a;
}
void star(int n, int row, int col){
    if(n%2==1){
        arr[row][col]='*';
        for(int i=0; i<pow(n)-2;i++){
            arr[row+i][col+i]='*';
            arr[row+i][col-i]='*';
        }
        for(int i=0; i<pow(n)-1;i++){
            arr[row+pow(n)-2][col+i]='*';
            arr[row+pow(n)-2][col-i]='*';
        }
    }
    else{
        arr[row][col]='*';
        for(int i=0; i<pow(n)-2;i++){
            arr[row-i][col+i]='*';
            arr[row-i][col-i]='*';
        }
        for(int i=0; i<pow(n)-1;i++){
            arr[row-pow(n)+2][col+i]='*';
            arr[row-pow(n)+2][col-i]='*';
        }
    }
    
    
    if(n!=1){
        if(n%2==1)
            star(n-1,row+pow(n)-3,col);
        else
            star(n-1,row-pow(n)+3,col);
    }
}
int main(){
    int n;
    cin >> n;

    int row= pow(n)-1;
    int col= pow(n+1)-3;
    for(int i=0; i< row;i++)
        for(int j=0; j<col; j++)
            arr[i][j]=' ';

    if (n%2 ==1)
        star(n, 0, (col+1)/2-1);
    else
        star(n, row-1, (col+1)/2-1);

    for(int i=0; i< row;i++){
        if(n%2==1){
            for(int j=0; j<row+i; j++)
                cout << arr[i][j];
        }
        else{
            for(int j=0; j<col-i; j++)
                cout << arr[i][j];
        }
        cout << endl;
    }
}