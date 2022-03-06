#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> s;
    int cnt=1;
    string ans;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        while(cnt <= x){
            s.push(cnt);
            cnt++;
            ans +="+";
        }
        if(s.top() != x){
            cout << "NO";
            return 0;
        }
        s.pop();
        ans += "-";
    }
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';
}