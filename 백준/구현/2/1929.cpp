#include<iostream>
using namespace std;
bool is_prime(int num){
    if (num==1)
        return false;
    else if (num ==2 || num ==3)
        return true;
    else{
        for(int i=2; i*i<=num; i++){
            if (num%i==0)
                return false;
        }
        return true;
    }
}
int main(){
    int m,n;
    cin >> m >> n;
    for(int i=m; i<=n; i++){
        if(is_prime(i))
            cout << i << '\n';
    }
}