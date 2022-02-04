#include<iostream>
using namespace std;
int main(){
    int people=0, max=0;
    for(int i=1; i<=4; i++){
        int in, out;
        cin >> out >> in;
        people-=out;
        people +=in;
        if( max < people)
            max=people;
    }
    cout << max;
}