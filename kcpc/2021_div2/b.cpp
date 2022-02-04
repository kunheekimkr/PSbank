#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector <int> c;
vector <int> w;
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        c.push_back(a);
    }

    for(int i=0; i<m; i++){
        int b;
        cin >> b;
        w.push_back(b);
    }
    
    sort(c.begin(),c.end());
    for(int i=0; i<m; i++){
        int max_index = max_element(c.end()-i, c.end()) - c.end()+i;
        if(c[max_index] < w[i]){
            cout << 0;
            return 0;
        }
        c[max_index]-=w[i];
    }
    cout << 1;

}