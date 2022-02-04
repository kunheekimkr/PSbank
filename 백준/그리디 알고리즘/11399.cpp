#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int>v;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int result=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<=i; j++){
            sum+=v[j];
        }
        result+=sum;
    }
    cout << result;
}