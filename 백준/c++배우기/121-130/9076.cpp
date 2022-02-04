#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int arr[5];
        int min=11, max=0;
        for(int i=0; i<5; i++){
            cin >> arr[i];        
        }
        for(int i=0; i<5; i++){
            for(int j=i+1; j<5; j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        if(arr[3]-arr[1]>=4)
            cout << "KIN" << endl;
        else
            cout << arr[1]+arr[2]+arr[3] << endl;

    }
}