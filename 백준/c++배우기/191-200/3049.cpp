#include<iostream>
using namespace std;
int main(){
    int v;
    cin >> v;
    if( v==3)
        cout << "0";
    else
        cout << v*(v-1)*(v-2)*(v-3)/24;
}