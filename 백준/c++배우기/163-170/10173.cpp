#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        if(s=="EOI")
            break;
        
        for(int i=0; i<s.size();i++){
            s[i]=tolower(s[i]);
        }
        if(s.find("nemo")==string::npos)
            cout << "Missing" << '\n';
        else
            cout << "Found" << '\n';
    }
}