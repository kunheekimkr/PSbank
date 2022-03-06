#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> s;
    long long ans=0;
    for(int i=0; i<n; i++){
        long long h;
        cin >> h;
        while(!s.empty() && s.top() <= h)
            s.pop();
        ans +=s.size();
        s.push(h);
    }
    cout << ans;
}