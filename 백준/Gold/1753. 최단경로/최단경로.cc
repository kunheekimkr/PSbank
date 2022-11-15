#include<iostream>
#include<vector>
#include<queue>

#define MAX 20001
#define INF 1000000
using namespace std;
int v,e,k;
vector<pair<int,int>> vertex[MAX];
int dist[MAX];

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[current]<cost) continue;
        for(int i=0; i< vertex[current].size(); i++){
            int next = vertex[current][i].first;
            int next_cost = vertex[current][i].second;
            if(dist[current] + next_cost < dist[next]) {
               dist[next] = dist[current] + next_cost;
               pq.push(make_pair(-dist[next],next));
            }  
        }
    }
    for(int i=1; i<=v; i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }else {
            cout << dist[i] << '\n';
        }
    }
}

int main(){
    cin >> v >> e;
    cin >> k;
    int a, b, c;
    for( int i=0; i<e; i++){
        cin >> a >> b >> c;
        vertex[a].push_back(make_pair(b,c));
    }
    for(int i=1; i<=v; i++){
        dist[i] = INF;
    }
    
    dijkstra(k);
}