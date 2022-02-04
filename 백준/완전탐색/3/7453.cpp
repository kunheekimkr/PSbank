#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long int arr[4][4000];
vector<int> halfsum;
long long int answer=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<4; j++)
            cin >> arr[j][i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            halfsum.push_back(arr[0][i]+arr[1][j]); //앞 두 행렬에서 수를 골라 더함

    sort(halfsum.begin(),halfsum.end());

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            long long int half=arr[2][i]+arr[3][j];

            //halfsum 의 값중 -half 보다 크거나 같은 가장 작은 값의 index low
            long long int low = lower_bound(halfsum.begin(),halfsum.end(),-half)-halfsum.begin();
            //halfsum 의 값중 -half 보다 작거나 같은 가장 큰 값의 index how
            long long int high = upper_bound(halfsum.begin(),halfsum.end(),-half)-halfsum.begin();

            if(-half == halfsum[low]) //
                answer += (high-low);           
        }
    cout << answer;
}