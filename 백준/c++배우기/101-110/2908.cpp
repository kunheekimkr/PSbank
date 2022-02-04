#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a;
    cin >> b;
    
    int num1,num2;
    num1= 100*(a%10)+a%100-a%10+a/100;
    num2= 100*(b%10)+b%100-b%10+b/100;
    if( num1< num2)
        cout << num2;
    else
        cout << num1;
}