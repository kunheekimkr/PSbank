#include<iostream>
#include<string>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        int n;
        string s;
        cin >> n >> s;
        bool ans = false;
        for(int i=0; i < s.size(); i++){
            if(check(i)){
                ans = true;
                break;
            }
        }
        cout << "Case #" << tc << ": ";
        if(ans)
            cout << "POSSIBLE\n";
        else
            cout << "IMPOSSIBLE\n";
    }
}