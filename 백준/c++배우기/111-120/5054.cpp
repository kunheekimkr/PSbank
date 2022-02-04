#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        int arr[a];
        int min=100, max=-1;    
        for(int i=0; i<a; i++){
            cin >> arr[i];
            if(arr[i]<min)
                min=arr[i];
            if(arr[i]>max)
                max=arr[i];
        }
        cout << 2*(max-min) << endl;
    }
}