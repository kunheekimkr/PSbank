#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        int lowercase=0;
        int highercase=0;
        int space=0;
        int number=0;
        for(int i=0;i<s.size();i++){
            if (s[i]>='a' && s[i]<='z')
                lowercase++;
            else if (s[i]>='A' && s[i]<='Z')
                highercase++;
            else if(s[i]>='0' && s[i]<='9')
                number++;
            else if (s[i]==' ')
                space++;
        }
        cout << lowercase << ' ' << highercase << ' ' << number << ' ' << space << '\n';
    }
}