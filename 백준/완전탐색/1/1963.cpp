#include<iostream>
#include<queue>
using namespace std;
int n,k;
bool isprime[10001];
int check[10001];
queue <int> q;
int pow(int a, int b){
    int result=1;
    for(int i=0; i<b; i++)
        result *= a;
    return result;
}

void sieve (){
    for(int i=0; i<10001; i++){
        isprime[i]=true;//초기화
    }
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2; i<=100; i++){
        if(isprime[i])
            for(int j=i*i; j<10001; j+=i){
                isprime[j]=false;
            }
    }
}
void search(){
    q.push(n);
    check[n]=1;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            for(int j=0;j<10;j++){ // i번쨰 자리수를 j로 치환 하여 next로 저장
                int next=current%(pow(10,3-i))+(current/pow(10,4-i))*pow(10,4-i)+j*pow(10,3-i);
                if(next>=1000 && isprime[next] && check[next]==0){
                    q.push(next);
                    check[next]=check[current]+1;
                }
            }
        }
    }
}


int main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        for(int i=0; i<10001; i++)
            check[i]=0; //초기화
        cin >> n >> k;
        search();
        if(check[k]!=0)
            cout << check[k]-1 << '\n';
        else
            cout << "Impossible\n";
    }
}