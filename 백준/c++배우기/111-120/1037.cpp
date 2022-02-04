#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int min=1000001, max=1;    
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]<min)
            min=a[i];
        if(a[i]>max)
            max=a[i];
    }
    cout << min*max;
}