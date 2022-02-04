#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s1,s2;
        cin >> s1 >> s2;
        cout << "Distances: ";
        for(int i=0; i<s1.size(); i++){
            if(s1[i]>s2[i])
                cout << 26- int(s1[i]-s2[i]) << ' ';
            else
                cout << int(s2[i]-s1[i]) << ' ';
        }
        cout << endl;
    }
}