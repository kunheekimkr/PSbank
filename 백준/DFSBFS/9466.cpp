#include<iostream>
#include<algorithm>
using namespace std;
int n, cnt, g[100001];
bool visited[100001], finished[100001];
// 처음 한 점을 탐색할때 visited= true;
// 그 점에서부터 시작하는 dfs 가 끝났을때 finished = true;

void dfs(int curr){
    visited[curr]=true;
    int next= g[curr];
    if(visited[next] == false)
        dfs(next);
    else if(finished[next] ==false){ // 싸이클 의 조건: 다음 점이 visited 이지만 finished 는 아닐 때!
        for(int temp=next; temp != curr; temp=g[temp])
            cnt++; //싸이클의 점 개수만큼 더함
        cnt++; // 싸이클의 시작점을 빼먹어서 더해줌
    }
    finished[curr]=true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> g[i];

        fill(finished,finished+100001,false);
        fill(visited,visited+100001,false);
        cnt=0;
        for(int i=1; i<=n; i++){
            if(visited[i]==false)
                dfs(i);
        }
        cout << n-cnt << '\n';
    }
}