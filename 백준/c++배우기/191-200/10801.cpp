#include<iostream>
using namespace std;
int main(){
    int a[10], b[10];
    for(int i=0;i<10;i++){
        cin >> a[i];
    }
    for(int i=0; i<10;i++){
        cin >> b[i];
    }
    int ap=0,bp=0;
    for(int i=0;i<10;i++){
        if(a[i]>b[i])
            ap++;
        else if (a[i]<b[i])
            bp++;
    }
    if(ap>bp)
        cout << 'A';
    else if (ap < bp)
        cout << 'B';
    else
        cout << 'D';
}