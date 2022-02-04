#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Graph{
    public:
        int N;
        vector<vector<int>> adj;
        vector<bool> visited;
        vector<bool> color; // bfs를 진행하며 순서대로 true/ false 를 각각 지정함
        bool is_bipartitegraph=true; //최종적으로 이분그래프의 여부를 저장

        Graph(): N(0){}
        Graph(int n): N(n){
            adj.resize(N+1);
            visited.resize(N+1);
            color.resize(N+1);
        }

        void addedge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }   

        void sortlist(){
            for(int i=0; i<=N; i++)
                sort(adj[i].begin(),adj[i].end());
        }

        void initiallize(){
            fill(visited.begin(),visited.end(),false);
        }

        void bfs(int start){
            queue<int> Q;
            Q.push(start);
            visited[start]=true;
            color[start]=true;
            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();
                for(int next: adj[curr]){
                    if(visited[next] == false){
                        visited[next] = true;
                        Q.push(next);
                        color[next]=!color[curr]; //인접한 두 점은 다른 color 로 저장
                    }
                    else{
                        if(color[next]==color[curr])
                            is_bipartitegraph=false; //인접한 두 점이 같은 color일 경우 이분그래프가 아님
                    }
                }
            }
        }
};

int main(){
    int k,v,e;
    cin >> k;
    while(k--){
        cin >> v >> e;
        Graph G(v);
        while(e--){
            int a,b;
            cin >> a >> b;
            G.addedge(a,b);
        }
        G.sortlist();
        G.initiallize();
        for(int i=1; i<=v; i++){
            if(G.visited[i] == false){
                G.bfs(i);
            }
        }
        if(G.is_bipartitegraph)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
