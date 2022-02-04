#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> v;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int m;
    cin >> m;
    while(m--){
        int num;
        cin >> num;
        int left=0;
        int right=n-1;
        int result=0;
        while(left <= right){
            int mid=(left+right)/2;
            if( v[mid] > num)
                right= mid-1;
            else if (v[mid] < num)
                left = mid+1;
            else{
                result=1;
                break;
            }
        }
        cout << result << ' ';
    }
}