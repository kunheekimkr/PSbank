#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int cnt=0;
        for(int i=n; i<=m; i++){
            if(i==0)
                cnt++;
            else{
                int temp=i;
                while(temp){
                    if(temp%10==0)
                        cnt++;
                    temp/=10;
                }
            }
        }
        cout << cnt << endl;
    }
}