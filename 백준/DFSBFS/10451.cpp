#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Graph{
    public:
        int N;
        vector<vector<int>> adj;
        vector<int> visited;

        Graph():N(0){}
        Graph(int n):N(n){
            adj.resize(n+1);
            visited.resize(n+1);
        }

        void addedge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void sortlist(){
            for (int i=0; i<= N; i++){
                sort(adj[i].begin(),adj[i].end());
            }
        }
        
        void initiallize(){
            fill(visited.begin(),visited.end(),false);
        }

        void dfs(int curr){
            visited[curr]=true;
            for( int next :adj[curr]){
                if( visited[next] == false)
                    dfs(next);
            }
        }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Graph G(n);
        for(int i=1; i<=n; i++){
            int a;
            cin >> a;
            G.addedge(i,a);
        }   
        G.sortlist();
        G.initiallize();
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(G.visited[i] == false){
                G.dfs(i);
                cnt++;
            }
        }
        cout << cnt <<"\n";
    }
}