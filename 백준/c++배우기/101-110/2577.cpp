#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int num=a*b*c;
    int digit[10]={0,0,0,0,0,0,0,0,0,0};
    while(num>0){
        digit[num%10]++;
        num/=10;
    }
    for(int i=0; i<10; i++)
        cout << digit[i] <<endl;
}   