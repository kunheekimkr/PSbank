#include<iostream>
using namespace std;
int main(){
    int arr[9];
    int max=0;
    int cnt;
    for(int i=0;i<9;i++){
        cin >> arr[i];
        if(max < arr[i]){
            max = arr[i];
            cnt= i;
        }
    }
    cout << max << endl << cnt+1 ;

}