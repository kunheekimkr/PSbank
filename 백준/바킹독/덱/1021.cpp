#include<deque>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    deque<int> d;
    for(int i=1; i<=n; i++)
        d.push_back(i);
    int ans=0;
    while(m--){
        int t;
        cin >> t;
        int idx =find(d.begin(), d.end(), t) -d.begin();
        while(d.front()!= t){
            if( idx < d.size() - idx){
                d.push_back(d.front());
                d.pop_front();
            }
            else{
                d.push_front(d.back());
                d.pop_back();
            }
            ans++;
        }
        d.pop_front();
    }
    cout << ans;
}