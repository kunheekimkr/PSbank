#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int arr[10];
        for(int i=0; i<10; i++){
            cin >> arr[i];
        }
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        cout << arr[7] << endl;        
    }
}