#include<iostream>
#include<vector>
using namespace std;
bool visited[100001]={false,};
vector<pair<int,int>> v[100001];
int ans=0;
int end_point=0;

void dfs(int point, int length){//가중치를 포함한 dfs
    if(visited[point])
        return;

    visited[point]=true;
    
    if(length > ans){
        ans=length;
        end_point=point;
    }
    for(int i=0; i<v[point].size();i++)
        dfs(v[point][i].first,v[point][i].second+length);

}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int p1;
        cin >> p1;
        while(true){
            int p2,len;
            cin >> p2;
            if(p2 == -1)
                break;
            cin >> len;
            v[p1].push_back(make_pair(p2,len));
            v[p2].push_back(make_pair(p1,len));
        }
    }
    dfs(1,0);// 우선 1번노드에서부터 dfs를 하여 가장 깊은 노드를 end_point에 저장. 이 점은 반드시 지름의 양 끝점 중 하나
    for(int i=0;i<=n;i++)
        visited[i]=false;//visited 배열 초기화
    dfs(end_point,0);
    cout << ans;
}