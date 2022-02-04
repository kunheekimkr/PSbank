#include<iostream>
#include<string>
using namespace std;

int main(){
    string n;
    int b;

    cin >> n >> b;
    long long int result=0;
    for(int i=0; i<n.size(); i++){
        if(n[i]>= 'A' && n[i] <= 'Z')
            result = result*b + n[i] - 'A' + 10;
        else
            result = result*b + n[i] - '0';
    }
    cout << result;
}