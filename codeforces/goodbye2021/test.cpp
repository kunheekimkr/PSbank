#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>n;
        string str;
        cin>>str;
        if(n>1&&str[0]==str[1]){
            cout<<str[0]<<str[0]<<'\n';
            continue;
        }
        for(i=1;i<n;i++){
            if(str[i]>str[i-1])break;
        }
        j=i-1;
        for(i=0;i<=j;i++){
            cout<<str[i];
        }
        for(i=j;i>=0;i--){
            cout<<str[i];
        }
        cout<<'\n';
    }

    return 0;
}