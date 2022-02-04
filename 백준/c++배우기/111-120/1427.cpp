#include<iostream>
using namespace std;
int main(){
    int arr[10];
    int i=0;
    int n=0;
    cin >> n;
    while(n){
        arr[i]=n%10;
        n=n/10;
        i++;
    }
    for(int j=0; j<i; j++){
        for(int k=j+1; k<i; k++){
            if(arr[j]>arr[k]){
                int temp=arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
            }
        }
    }
    for(int j=i-1; j>=0 ; j--){
        cout << arr[j];
    }    
}