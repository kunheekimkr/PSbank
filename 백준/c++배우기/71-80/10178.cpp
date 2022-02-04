#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while (n--){
        int candy, person;
        cin >> candy >> person;
        cout << "You get " << candy/person << " piece(s) and your dad gets " << candy%person << " piece(s)." << endl;
    }
}