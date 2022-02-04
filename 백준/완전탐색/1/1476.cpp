#include<iostream>
using namespace std;
int main(){
    int e=15;
    int s=28;
    int m=19;
    int ei,si,mi;
    for(ei=1; ei<15; ei++){
        if(ei*s*m%15==1)
            break;
    }
    for(si=1; si<28; si++){
        if(si*e*m%28==1)
            break;
    }
    for(mi=1; mi<19; mi++){
        if(mi*e*s%19==1)
            break;
    }
    int a,b,c;
    cin >> a >> b >> c;
    int result=(a*ei*s*m+b*si*e*m+c*mi*e*s)%(e*s*m);
    if(result>0)
        cout << result;
    else
        cout << 15*28*19;
}