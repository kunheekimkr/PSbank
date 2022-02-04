#include<iostream>
using namespace std;
int main(){
    int a[10]={0,};
    int arr[100]={0,};
    int sum=0;
    for (int i=0; i<10; i++){
        cin >> a[i];
        sum += a[i];
        arr[a[i]/10]++;
    }
    cout << sum/10 << endl;
    int max=0;
    int temp;
    for( int i=1; i<100; i++){
        if(max < arr[i]){
            max=arr[i];
            temp=i;
        }
    }
    cout << temp*10 <<endl;
}