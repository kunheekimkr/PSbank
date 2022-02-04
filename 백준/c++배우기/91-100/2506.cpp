#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int point=0;
    int streak=1;
    while (n--){
        int ox;
        cin >> ox;
        if( ox ==1){
            point+=streak;
            streak++;
        }
        else
            streak=1;
    }
    cout << point ;
}