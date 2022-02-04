#include<iostream>
#include<string>
using namespace std;

int rps (string a, string b){
    if(a==b)
        return  0;
    else if ((a=="R" && b=="S") || (a=="P" && b=="R")  || (a=="S" && b=="P"))
        return 1;
    else
        return 2;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a=0, b=0;
        int n;
        cin >> n;
        while(n--){
            string p1, p2;
            cin>> p1 >> p2;
            int result=rps(p1,p2);
            if(result==1)
                a++;
            else if (result ==2)
                b++;
        }
        if(a>b)
            cout << "Player 1" << '\n';
        else if (a<b)
            cout << "Player 2" << '\n';
        else
            cout << "TIE" << '\n';

    }
}