#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> v;
int lower(int num){ //찾는 값 이상의 수가 처음 나타나는 위치
    int left=0;
    int right=v.size()-1;
    while(right >= left){
        int mid=(left+right)/2;
        if(v[mid]>= num )
            right=mid-1;
        else
            left=mid+1;
    }
    return right;
}

int upper(int num){ // 찾는 값보다 큰 수가 처음 나타나는 위치
    int left=0;
    int right=v.size()-1;
    while(right >= left){
        int mid=(left+right)/2;
        if(v[mid]> num )
            right=mid-1;
        else
            left=mid+1;
    }
    return right;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
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
        int answer=upper(num)-lower(num); // 숫자의 개수= upper -lower
        cout << answer << ' ';
    }
}