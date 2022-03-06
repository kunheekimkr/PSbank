#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        string s;
        cin >> s;
        int n;
        cin >> n;
        string str; 
        cin >> str;
        deque<int> d;
        int cur=0;
        for(int i=1; i<str.size()-1; i++){
            if(str[i] == ','){
                d.push_back(cur);
                cur=0;
            }
            else
                cur = 10* cur + (str[i] - '0');
        }
        if(cur!=0)
            d.push_back(cur);

        bool is_left = true;
        bool is_error = false;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='R')
                is_left = !is_left;
            else if (s[i]=='D'){
                if(d.empty()){
                    is_error =true;
                    break;
                }
                else{
                    if(is_left)
                        d.pop_front();
                    else
                        d.pop_back();
                }
            }
        }
        if(is_error)
            cout << "error\n";
        else{
            cout << '[';
            if(is_left){
                for(int i = 0; i < d.size(); i++){
                    cout << d[i];
                    if(i+1 != d.size())
                        cout << ',';
                }
            }
            else {
                for(int i = d.size()-1; i >= 0 ; i--){
                    cout << d[i];
                    if(i!=0)
                        cout << ',';
                }
            }
            cout << "]\n";
        }
    }
}