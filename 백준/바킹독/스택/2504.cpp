#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> s;
    int sum =0;
    int num=1;

    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            num *=2;
            s.push(str[i]);
        }
        else if (str[i] == '['){
            num *=3;
            s.push(str[i]);
        }
        else if (str[i] == ')'){
            if(s.empty() || s.top() != '('){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '(')
                sum += num;
            s.pop();
            num /= 2;
        }
        else if (str[i] == ']'){
            if(s.empty() || s.top() != '['){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[')
                sum += num;
            s.pop();
            num /= 3;
        }
    }
    if(s.empty())
        cout << sum;
    else
        cout << 0;
}
