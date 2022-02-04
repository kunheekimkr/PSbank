#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t;
int n,m;
int a[1000],b[1000];
long long answer=0;
vector<int> sum_a,sum_b;

int main(){
    cin >> t;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    cin >> m;
    for(int i=0; i<m; i++)
        cin >> b[i];

    for(int i=0; i<n; i++){
        int sum=a[i];
        sum_a.push_back(sum);
        for(int j=i+1; j<n; j++){
            sum+=a[j];
            sum_a.push_back(sum);
        }
    }

    sort(sum_a.begin(),sum_a.end());

    for(int i=0; i<m; i++){
        int sum=b[i];
        sum_b.push_back(sum);
        for(int j=i+1; j<m; j++){
            sum+=b[j];
            sum_b.push_back(sum);
        }
    }

    for(int i=0; i<sum_b.size(); i++){
        int sum=t-sum_b[i];
        answer += (upper_bound(sum_a.begin(),sum_a.end(),sum) - lower_bound(sum_a.begin(),sum_a.end(),sum));
    }

    cout << answer;
}