#include<iostream>
#include<vector>
using namespace std;
bool visited[10002]={false,};
vector<pair<int,int>> v[10002];
int ans=0;
int end_point=0;

void dfs(int point ,int length){ //가중치를 포함한 dfs
    if(visited[point])
        return;
    
    visited[point]=true;
    if(ans<length){
        ans=length;
        end_point = point;
    }
    for(int i=0; i<v[point].size(); i++){
        dfs(v[point][i].first,length+v[point][i].second);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b,len;
        cin >> a >> b >> len;
        v[a].push_back(make_pair(b,len));
        v[b].push_back(make_pair(a,len));
    } 
    dfs(1,0); // 우선 1번노드에서부터 dfs를 하여 가장 깊은 노드를 end_point에 저장. 이 점은 반드시 지름의 양 끝점 중 하나

    for(int i=0; i<=n; i++){
        visited[i]=false; //visited 배열 초기화
    }

    dfs(end_point,0);
    cout << ans;
}