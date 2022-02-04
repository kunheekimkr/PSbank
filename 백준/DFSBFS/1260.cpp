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
    
        Graph(): N(0){}
        Graph(int n): N(n){
            adj.resize(N+1);
            visited.resize(N+1);
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

        void dfs(int curr){
            visited[curr] = true;
            cout << curr << " ";
            for(int next: adj[curr]){
                if(visited[next] == false)
                    dfs(next);
            }
        }
        
        void bfs(int start){
            queue<int> Q;
            Q.push(start);
            visited[start]=true;
            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();
                cout << curr << " ";
                for(int next: adj[curr]){
                    if(visited[next] == false){
                        visited[next] = true;
                        Q.push(next);
                    }
                }
            }
        }


};

int main(){
    int n,m,v;
    cin >> n >> m >> v;
    Graph G(n);
    while(m--){
        int a,b;
        cin >> a >> b;
        G.addedge(a,b);
    }
    G.sortlist();
    G.initiallize();
    G.dfs(v);
    G.initiallize();
    cout << '\n';
    G.bfs(v);    
}
