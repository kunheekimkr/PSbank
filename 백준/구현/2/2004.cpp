#include<iostream>
int five(int n){
    int result=0;
    while(n){
        result+=n/5;
        n/=5;
    }
    return result;
}
int two(int n){
    int result=0;
    while(n){
        result+=n/2;
        n/=2;
    }
    return result;
}

using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int f= five(n)-five(m)-five(n-m);
    int t= two(n) -two(m) -two(n-m);
    if( f> t)
        cout << t;
    else
        cout << f;

}