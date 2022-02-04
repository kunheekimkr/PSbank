#include<iostream>
using namespace std;
bool isprime(int n){
    if(n==1)
        return false;

    for(int i=2; i<32; i++){
        if( n!=i){
            if(n%i==0)
                return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int cnt=0;
    while(n--){
        int num;
        cin >> num;
        if(isprime(num))
            cnt++;
    }
    cout << cnt;
}