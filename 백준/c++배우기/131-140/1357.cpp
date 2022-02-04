#include<iostream>
using namespace std;
int rev(int x){
    int result=0;
    while(x){
        result*=10;
        result+=x%10;
        x/=10;
    }
    return result;
}
int main(){
    int x,y;
    cin >> x >> y;
    cout << rev(rev(x)+rev(y));
}