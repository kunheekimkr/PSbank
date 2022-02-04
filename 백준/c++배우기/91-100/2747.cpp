#include<iostream>
using namespace std;
long long fb[45];
long long fibonacci(int n){
    if(n==0)
        return 0;
    if (n ==1)
        return 1;
    if (fb[n]!=0)
        return fb[n];
    else 
        fb[n]=fibonacci(n-1)+fibonacci(n-2);    
    return fb[n];
}

int main(){
    int n;
    cin >> n;
    cout << fibonacci(n);
}