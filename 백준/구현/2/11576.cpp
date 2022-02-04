#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int m;
    cin >> m;
    long long result=0;
    while(m--){
        int n;
        cin >> n;
        result=result*a+n;
    }
    stack<int> s;
    while (result>0){
        s.push(result%b);
        result/=b;
    }
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
}