#include<iostream>
#include<vector>
using namespace std;
int arrows(int arr[], int a, int n){
    int sum=0;
    for(int i=0; i<a; i++)
        sum+=arr[i];
    return (n-sum);
}
int main(){
    int c[11]={2,1,1,1,0,0,0,0,0,0,0};
    cout << arrows(c,5,11);
}