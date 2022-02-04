#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int k,n;
    cin >> k >> n;
    vector<long long> v;
    for(int i=0; i<k; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    long long left=1;
    long long right=v[k-1];
    long long result=0;
    while(right>=left){
        long mid=(left+right)/2;
        int cnt=0;
        for(int i=0; i<k; i++)
            cnt+=v[i]/mid;
        if(cnt >=n){
            if(result<mid)
                result=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout << result;
}