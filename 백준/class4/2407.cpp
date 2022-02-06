#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string c[101][101];

string stringsum (string a, string b){
    while(a.size() > b.size()){
        b= "0" + b;
    }
    while(a.size() < b.size()){
        a= "0" + a;
    }

    string result;
    int up=0;
    for(int i=a.size()-1;  i>=0; i--){
        int na= a[i] - '0';
        int nb= b[i] - '0';
        int res = na + nb + up;
        up =res/10;
        res %=10;

        char temp = res + '0';
        result = temp + result;
    }
    if(up==1)
        result = '1' + result;
    
    return result;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j ==0 || j==i)
                c[i][j] = "1";
            else
                c[i][j] = stringsum(c[i-1][j-1] ,c[i-1][j]);
            
        }
    }
    cout << c[n][m];
}