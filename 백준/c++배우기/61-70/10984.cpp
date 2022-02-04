#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int total=0;
        double sum=0,gpa=0;
        while(n--){
            int credit;
            double grade;
            cin >> credit >> grade;
            total+=credit;
            sum+=credit*grade;
        }
        gpa=sum/total;
        cout << fixed;
        cout.precision(1);
        cout<< total << ' ' << gpa << endl;
    }
}