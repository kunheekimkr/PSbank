#include<iostream>
using namespace std;
int main(){
    int max=-1, temp=0;
    for(int i=1; i<=5; i++){
        int sum=0;
        for(int j=0; j<4; j++){
            int a;
            cin >> a;
            sum+=a;
            if(sum>max){
                temp=i;
                max=sum;
            }
        }
    }
    cout << temp << ' ' << max;
}