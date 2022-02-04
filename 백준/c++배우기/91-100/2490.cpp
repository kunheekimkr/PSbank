#include<iostream>
using namespace std;
int main(){
    for(int i=1; i<=3; i++){
        int cnt=0;
        for(int j=1; j<=4; j++){
            int n;
            cin >> n;
            if(n==0)
                cnt++;
        }
        if(cnt==1)
            cout << 'A' << endl;
        else if (cnt ==2)
            cout << 'B' << endl;
        else if (cnt==3)
            cout << 'C' << endl;
        else if (cnt==4)
            cout << 'D' << endl;
        else if (cnt==0)
            cout << 'E' << endl;
    }
}