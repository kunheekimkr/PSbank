#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> tree[100001];
bool visited[100001];
int parent[100001];
void findparent(int node){
    visited[node]=true;
    for(int i=0; i<tree[node].size();i++){
        int next=tree[node][i];
        if(!visited[next]){
            parent[next]=node;
            findparent(next);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    findparent(1);
    for(int i=2; i<=n; i++)
        cout << parent[i] << '\n';
}