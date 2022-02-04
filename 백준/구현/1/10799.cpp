/*조각의 수= 각 레이저가 자르는 막대의 수 의 총합 + 총 막대의 개수*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char> st;
    int num=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' && s[i+1]==')'){ //레이저인 경우
                num+=st.size(); // 각 레이저가 자르는 막대의 수
                st.push('(');
        }
        else{
            if(s[i]=='('){ //막대 추가
                num++;
                st.push('(');
            }
            else
                st.pop();
        }
    }
    cout << num;
}
