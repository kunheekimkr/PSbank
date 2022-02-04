#include<iostream>
#include<vector>
using namespace std;
int n;
vector <int> prime;
bool is_prime[4000001];
void sieve(int n){
    for (int i=0; i<=n; i++)
        is_prime[i]=true;
    
    for(int i=2; i*i <=n; i++){
        if(is_prime[i]==false){
            continue;
        }

        for(int j= i*i ;j<=n;j+=i)
            is_prime[j]=false;   
    }
    
    for (int i=2; i<=n; i++)
        if (is_prime[i]==true)
            prime.push_back(i);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if (n==1){
        cout << 0;
        return 0;
    }
    sieve(n);
    int num=prime.size();
    int start=0;
    int end=0;
    int cnt=0;
    int sum=prime[0];
    while (true){ 
        if (end >= num)
            break;
        if(sum == n)
            cnt++;
        if(sum <= n){ 
            end++;
            sum+=prime[end];
        }
        else{ 
            sum-=prime[start];
            start++;
        }
    }
    cout << cnt;
}