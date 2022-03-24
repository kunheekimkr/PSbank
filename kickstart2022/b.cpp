#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        string n;
        cin >> n;
        int size =n.size();
        int sum = 0;
        for(int i=0; i< size; i++)
            sum += (n[i] - '0');
        int newdigit = 9 - sum % 9;
        if(newdigit ==9)
            newdigit = 0;

        cout << "Case #" << tc << ": ";
        if(newdigit ==0){
            cout << n[0];
            cout << newdigit;
            for(int i = 1; i<size; i++)
                cout << n[i];
        }
        else{
            int i = 0;
            for(i; i<size; i++){
                if( n[i] <= newdigit + '0')
                    cout << n[i];
                else
                    break;
            }
            cout <<  newdigit ;
            for(i; i<size; i++){
                cout << n[i];
            }
        }
        cout << '\n';
    }
}