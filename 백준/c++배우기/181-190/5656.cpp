#include<iostream>
#include<string>
using namespace std;
int main(){
    int cnt=0;
    while (true){
        cnt++;
        int a, b;
        string s;
        cin >> a >> s >> b;
        if(s=="E")
            break;
        cout << "Case " << cnt << ": ";
        
        if(s==">"){
            if (a>b)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(s==">="){
            if (a>=b)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(s=="<"){
            if (a<b)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(s=="<="){
            if (a<=b)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(s=="=="){
            if (a==b)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(s=="!="){
            if (a!=b)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
}