#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum=0;
    while(n--){
        int student, apple;
        cin >> student >> apple;
        sum+=apple%student;
    }
    cout << sum;
}