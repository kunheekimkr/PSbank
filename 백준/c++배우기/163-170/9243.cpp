#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    if(n%2==0){
        if(a==b)
            cout << "Deletion succeeded";
        else
            cout << "Deletion failed";
    }
    else{
        int cnt=0;
        for(int i=0; i<a.size();i++){
            if(a[i]==b[i])
                cnt++;
        }
        if(cnt==0)
            cout << "Deletion succeeded";
        else
            cout << "Deletion failed";
    }
}