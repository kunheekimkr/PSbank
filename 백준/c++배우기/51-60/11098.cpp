#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int p;
        cin >> p;
        int tempprice=0;
        string tempname;
        while (p--){
            int price;
            string name;
            cin >> price >> name;
            if(tempprice < price){
                tempprice=price;
                tempname=name;
            }
        }
        cout << tempname << endl;
    }

}