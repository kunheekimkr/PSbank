#include<iostream>
using namespace std;

bool broken[10]={false,};

int abs(int a){
    if(a>0)
        return a;
    else
        return -a;
}

int check(int n){
    if(n ==0){
        if(broken[0]){
            return 0;
        }
        else
            return 1;
    }
    int result=0;
    while(n>0){
        if(broken[n%10])
            return 0;
        n/=10;
        result++;
    }
    return result;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        broken[temp]=true;
    }

    int result=abs(100-n);
    for(int i=0; i<= 1000000; i++){
        int len=check(i);
        if(len>0){
            if(result > len+abs(n-i)){
                result=len+abs(n-i);
            }
        }
    }
    cout << result;
}