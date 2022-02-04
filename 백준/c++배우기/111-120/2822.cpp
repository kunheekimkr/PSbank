#include<iostream>
using namespace std;
int main(){
    int a[8];
    for(int i=0; i<8; i++){
        cin >> a[i];
    }
    int temp=0;
    int total=0;
    int arr[5];
    for(int i=0; i<8;i++){
        int cnt=0;
        for(int j=0;j<8;j++){
            if(a[j]>a[i])
                cnt++;
        }
        if(cnt<5){
            total+=a[i];
            arr[temp++]=i+1;
        }
    }
    cout << total <<endl;
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << ' ' << arr[4];
}