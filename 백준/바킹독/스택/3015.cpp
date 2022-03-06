#include<iostream>
#include<utility>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    stack< pair<int,int> > s;
    long long ans=0;
    for(int i=0; i<n; i++){
        long long h;
        cin >> h;
        int cnt=1;
        while(!s.empty() && s.top().first <= h){
            ans += s.top().second;
            if(s.top().first == h)
                cnt += s.top().second;
            s.pop();
        }
        if(! s.empty())
            ans ++;
        s.push( make_pair(h, cnt));
    }
    cout << ans;
}