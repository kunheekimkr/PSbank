#include<iostream>
#include<stack>
using namespace std;
int a[1000000];
int ans[1000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    stack<int> s;
    for(int i=n-1; i >=0; i--){
        while(!s.empty() && a[i] >= s.top())
            s.pop();
        if(s.empty())
            ans[i]=-1;
        else
            ans[i]=s.top();
        s.push(a[i]);
    }
    for(int i=0; i<n; i++)
        cout << ans[i] << ' ';
}