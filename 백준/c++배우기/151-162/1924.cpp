#include<iostream>
#include<string>
using namespace std;
int main(){
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

    int m, d;
    cin >> m >> d;

    int p=0;
    for(int i=1; i<m; i++){
        p+=month[i];
    }
    p+=d-1;

    cout << day[p%7];
}