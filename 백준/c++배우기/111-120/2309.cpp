#include<iostream>
using namespace std;
int main(){
    int arr[9];
    int sum=0;
    for(int i=0; i<9; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    int temp1, temp2;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sum-arr[i]-arr[j]==100){
                arr[i]=0;
                arr[j]=0;
                goto EXIT;
            }
        }
    }
    EXIT:
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=2; i<9; i++){
        cout << arr[i] << endl;
    }
}