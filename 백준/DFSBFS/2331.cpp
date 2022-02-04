#include<iostream>
using namespace std;
int v[240000]={0,};

int pow(int a,int p){
    int result=1;
    for(int i=0; i<p; i++)
        result *= a;
    return result;
}

void visit(int a,int p){
    v[a]++;

    if (v[a] ==3)
        return;

    int result=0;
    while(a>0){
        result += pow(a%10,p);
        a/=10;
    }
    visit(result,p);
}

int main(){
    int a,p;
    cin >> a >> p;
    visit(a,p);

    int cnt=0;
    for(int i=0; i<240000; i++){
        if(v[i]==1)
            cnt++;
    }
    cout << cnt;
}