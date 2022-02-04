#include<iostream>
using namespace std;
int main(){
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    int result=0;
    bool failure=false;
    int i=0;
    for(i=0; i<1000000; i++){
        if(s==g){
            cout << result;
            break;
        }
        if(s+u>f && s-d<1){
            failure=true;
            break;
        }
        if(s<g && s+u<=f){
            result++;
            s+=u;
        }
        else{
            result++;
            s-=d;
        }
    }
    if(i==1000000 || failure)
        cout <<"use the stairs";
}