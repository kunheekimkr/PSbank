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

        int dfs(int curr){
            int nodes=1;
            visited[curr] = true;
            for(int next: adj[curr]){
                if(visited[next] == false)
                    nodes += dfs(next);
            }
            return nodes;
        }
};

int main(){
    int n;
    cin >> n;
    int arr[n*n+1];
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        for(int j=1; j<=n; j++){
            arr[n*i+j]=temp[j-1];
        }
    }
    Graph G(n*n);
    for(int i=1; i<=n*(n-1); i++){
        if(i%n !=0){
            if(arr[i]=='1' && arr[i+1]=='1')
            G.addedge(i,i+1);
        }
        if(arr[i]=='1' && arr[i+n]=='1')
            G.addedge(i,i+n);
    }
    for(int i=n*(n-1)+1; i<n*n; i++){
        if(arr[i]=='1'&& arr[i+1]=='1')
            G.addedge(i,i+1);        
    }

    G.sortlist();
    G.initiallize();
    vector<int> length;
    int cnt=0;
    for(int i=1; i<=n*n; i++){
        if(G.visited[i]==false && arr[i]=='1'){
            cnt++;
            length.push_back(G.dfs(i));
        }
    }
    sort(length.begin(),length.end());
    cout << cnt << '\n';
    for(int i=0; i<length.size(); i++)
        cout << length[i] << '\n';


}
