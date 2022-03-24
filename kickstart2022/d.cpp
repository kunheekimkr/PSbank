#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        long long a, b;
        cin >> a >> b;
        long long ans=0;
        for(long long i=a; i<=b; i++){
            long num = i;
            long sum =0;
            long product = 1;
            while(num){
                sum += num%10;
                product *= num%10;
                num /= 10;
            }   
            if( product % sum ==0)
                ans++;
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}