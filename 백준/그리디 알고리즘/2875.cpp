#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    
    int maxteam=min(n/2,m);
    int intern= m+n-3*maxteam;
    while(intern<k){
        maxteam--;
        intern+=3;
    }
    cout << maxteam;
}