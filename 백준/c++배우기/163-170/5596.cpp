#include<iostream>
using namespace std;
int main(){
    int s=0;
    int t=0;
    int a,b,c,d;
    cin >> a >> b >> c >> d ;
    s=a+b+c+d;
    cin >> a >> b >> c >> d ;
    t=a+b+c+d;    
    int result= (s>=t) ? s : t;
    cout << result << endl;
}