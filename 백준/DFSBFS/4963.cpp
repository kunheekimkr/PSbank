#include<iostream>
#include<vector>
#include<string>
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
            int nodes=1;
            visited[curr] = true;
            for(int next: adj[curr]){
                if(visited[next] == false)
                    dfs(next);
            }
        }
};

int main(){
    while(true){
        int w, h;
        cin >> w >> h;
        if(w==0 && h==0)
            break;
        int arr[w*h+1];
        for(int i=1; i<=w*h; i++){
            cin >> arr[i];
        }
        Graph G(w*h);
        for(int i=1; i<=w*(h-1); i++){
            if(i%w !=0){
                if(arr[i]==1 && arr[i+1]==1)
                    G.addedge(i,i+1);
                if(arr[i]==1 && arr[i+w+1]==1)
                    G.addedge(i,i+w+1);
            }
            if(i%w !=1)
                if(arr[i]==1 && arr[i+w-1]==1)
                    G.addedge(i,i+w-1);
            if(arr[i]==1 && arr[i+w]==1)
                G.addedge(i,i+w);
        }
        for(int i=w*(h-1)+1; i<w*h; i++){
            if(arr[i]==1&& arr[i+1]==1)
                G.addedge(i,i+1);        
        }

        G.sortlist();
        G.initiallize();
        int cnt=0;
        for(int i=1; i<=w*h; i++){
            if(G.visited[i]==false && arr[i]==1){
                cnt++;
                G.dfs(i);
            }
        }
    cout << cnt << '\n';
    }
}