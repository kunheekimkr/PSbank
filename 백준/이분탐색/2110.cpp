#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,c;
    cin >> n >> c;
    vector <int> v;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int left=1;
    int right=v[n-1]-v[0];
    int result=0;
    while(left <= right){
        int mid =(left+right)/2;
        int cnt=1;
        int prev=v[0];
        for(int i=1; i<n;i++){
            if(v[i]-prev >=mid){
                cnt++;
                prev=v[i];
            }
        }

        if(cnt >= c){
            if(mid > result)
                result=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout << result;
}