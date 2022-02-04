#include<iostream>
using namespace std;
int main(){
    int sum;
    cin >> sum;
    int i=9;
    while (i--){
        int price;
        cin >> price;
        sum-=price;
    }
    cout << sum;
}