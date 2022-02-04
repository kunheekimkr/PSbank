#include<iostream>
#include<string>
#include<list>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    list<char> l(s.begin(),s.end());
    list<char>::iterator cursor=l.end();
    while(n--){
        
        char order;
        cin >> order;
        if(order=='L'){
            if(cursor !=l.begin())
                cursor--;
        }
        else if(order=='D'){
            if(cursor !=l.end())
                cursor++;
        }
        else if (order=='B'){
            if(cursor !=l.begin()){
                cursor--;
                cursor=l.erase(cursor);
            }
        }
        else if (order=='P'){
            char c;
            cin >> c;
            l.insert(cursor,c);
        }
    }

    for(list<char>::iterator i=l.begin(); i!=l.end(); i++){
        cout << *i;
    }
    return 0;
}