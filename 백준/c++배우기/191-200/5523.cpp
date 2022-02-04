#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a=0,b=0;
    while(n--){
        int ap, bp;
        cin >> ap >> bp;
        if(ap > bp)
            a++;
        else if (ap < bp)
            b++;
    }
    cout << a << ' ' << b;
}