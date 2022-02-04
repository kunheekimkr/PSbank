#include<iostream>
using namespace std;
int main(){
    int l,p;
    cin >> l >> p;
    int people=l*p;
    int news[5];
    for(int i=0;i<5;i++){
        cin >> news[i];
        cout << news[i]-people <<' ';
    }

}