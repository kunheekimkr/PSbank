#include<iostream>
#include<string>
using namespace std;
int main(){
    string max, doct;
    cin >> max >> doct;
    if(max.size()>= doct.size())
        cout << "go";
    else
        cout << "no";
}