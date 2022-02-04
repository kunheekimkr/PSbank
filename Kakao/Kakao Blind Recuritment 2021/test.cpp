#include<iostream>
#include<typeinfo>
#include<string>
using namespace std;
int main(){
    string s= "Hello";
    cout << typeid(s[2]).name();   
}