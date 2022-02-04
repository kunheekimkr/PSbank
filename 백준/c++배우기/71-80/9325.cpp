#include<iostream>
using namespace std;
int main(){
    int cnt;
    cin >> cnt;
    while(cnt--){
        int s;
        cin >> s ;
        int n;
        cin >> n;
        while(n--){
            int q,p;
            cin >> q >> p;
            s+=q*p;
        }
        cout << s << endl;
    }
}