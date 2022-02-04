#include<iostream>
#include<map>
using namespace std;
int n,s;
long long answer;
int arr[41];
map<int,int> halfsum;

void dfs_left(int index, int sum){ // 왼쪽 절반에서 파생되는 부분집합의 합 계산
    if(index == n/2){ // 합이 sum인 부분집합의 개수를 halfsum[sum]에 저장
        halfsum[sum]++;
        return;
    }
    dfs_left(index+1,sum); //index를 부분집합에 포함시키지 않고 다음 탐색
    dfs_left(index+1,sum+arr[index]); //index를 부분집합에 포함시키고 다음 탐색
}

void dfs_right(int index, int sum){// 오른쪽 절반에서 파생되는 부분집합의 합 계산
    if (index ==n){
        answer +=halfsum[s-sum]; //왼쪽 부분집합의 합이 s-sum, 오른쪽 부분집합의 합이 sum 이라면 두 집합의 합집합이 
        return;
    }
    dfs_right(index+1,sum); //index를 부분집합에 포함시키지 않고 다음 탐색
    dfs_right(index+1,sum +arr[index]); //index를 부분집합에 포함시키고 다음 탐색
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    dfs_left(0,0);
    dfs_right(n/2,0);
    if (s==0)
        answer--;
    cout << answer;
}