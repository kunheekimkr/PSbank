#include<iostream>
using namespace std;
bool isprime(int n){
    if(n==1)
        return false;

    for(int i=2; i<100; i++){
        if( n!=i){
            if(n%i==0)
                return false;
        }
    }
    return true;
}
int main(){
    int m,n;
    cin >> m >> n;
    int sum=0,min=0;
    for (int i=n; i>=m; i--){
        if(isprime(i)){
            sum+=i;
            min=i;
        }
    }
    if (min==0)
        cout << "-1";
    else
        cout << sum << endl << min;
}