#include<iostream>
using namespace std;
int main(){
    int k;
    cin >>k;
    for(int i=1; i<=k; i++){
        cout << "Class " << i << endl;
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        int max=0;
        for(int i=0; i<n-1; i++){
            int gap=arr[i+1]-arr[i];
            if(gap>max)
                max=gap;
        }
        cout << "Max " << arr[n-1] << ", Min " << arr[0] << ", Largest gap " << max << endl;
    }
}