#include<iostream>
using namespace std;
int is_prime[1000001]={0,};
void eratostenes(){
    for(int i=2; i*i < 1000001; i++){
        if(!is_prime[i]){
            for(int j=i*i; j<1000001; j+=i){
                is_prime[j]=1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
    int n;
    eratostenes();
    while(1){
        cin >> n;
        if(n ==0)
            break;
        for(int i=3; i<=n/2; i++){
            if(is_prime[i]==0 && is_prime[n-i]==0){
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
            else if (i ==n/2)
                cout << "Goldbach's conjecture is wrong." << "\n";
        }
    }
}