#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int pc=1-n;
    while (n--){
        int plug;
        cin >> plug;
        pc+=plug;
    }
    cout << pc;
}