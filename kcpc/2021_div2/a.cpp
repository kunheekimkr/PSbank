#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int curr;
    cin >> curr;
    long long ans=0;
    while(n--){
        int next;
        cin >> next;
        int a= next-curr;
        if(a<0)
            a=-a;
        int b=360-a;
        ans+=min(a,b);
        curr = next;
    }
    cout << ans;
}