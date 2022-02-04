#include<iostream>
using namespace std;
int main(){
    int min=100, sum=0;
    for(int i=1; i<=7;i++){
        int n;
        cin >> n;
        if(n%2==1){
            sum+=n;
            if(n<min)
                min=n;
        }
    }
    if (min==100){
        cout << "-1";
    }
    else
        cout << sum << endl << min;
}