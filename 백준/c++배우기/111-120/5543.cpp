#include<iostream>
using namespace std;
int min(int a, int b, int c){
    if(a < b){
        if(b < c)
            return a;
        else if (a < c )
            return a;
        else
            return c;
    }
    else{
        if(a < c)
            return b;
        else if (b < c)
            return b;
        else
            return c;
    }
}

int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min(a,b,c) + min(d,e) -50;
}