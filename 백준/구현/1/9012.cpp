#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        stack<char> st;
        for(int i=0; i<s.size() ; i++){
            if(s[i]=='(') 
                st.push('!');  // '(' 가 들어올때마다 stack을 쌓음
            else{
                if(st.empty()){
                    cout << "NO" << '\n'; // '(' 보다 ')'의 개수가 많아지는 순간 거짓
                    break;
                }
                else{
                    st.pop();
                }
            }
            if( i==s.size()-1){
                if(st.empty())
                    cout << "YES" << '\n'; // 마지막에 '('와')'의 개수가 같아야 참
                else
                    cout << "NO" << '\n';                      
            }      
        }
    }
}