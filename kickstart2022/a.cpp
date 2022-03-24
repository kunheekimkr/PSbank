#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        string i, p;
        cin >> i >> p;
        int ans =0;
        int size_i = i.size();
        int size_p = p.size();
        int j=0;
        int k=0;
        cout << "Case #" << tc <<": ";
        for(j; j<size_i; j++){
            while(k <size_p && i[j] != p[k])
                k++;
            if( k == size_p)
                break;
            k++;
        }
        if( j == size_i)
            cout << p.size() - i.size() << '\n';
        else
            cout << "IMPOSSIBLE\n";

    }
}