#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while (n--){
        int a;
        string word;
        cin >> a >> word;
        for( int i=0; i<word.size();i++){
            if(i != a-1)
                cout << word[i];
        }
        cout << endl;
    }
}