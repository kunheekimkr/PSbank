#include<iostream>
#include<string>
using namespace std;
int main(){
    while(true){
        string s;
        getline(cin,s);
        if(s=="")
            break;
        cout << s << endl;
    }
}