#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    long long n,m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0; i<n; i++){
        long long tree;
        cin >> tree;
        v.push_back(tree);
    }
    sort(v.begin(),v.end());
    long long left=1;
    long long right=v[n-1];
    long long answer=0;
    while(right>=left){
        long long mid=(left+right)/2;
        long long cnt=0;
        for(int i=0; i<n; i++){
            if(v[i]>mid)
                cnt+=(v[i]-mid);
        }
        if(cnt >= m){
            if(answer<mid)
                answer=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    cout << answer;
}