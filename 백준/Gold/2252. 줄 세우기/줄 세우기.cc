#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    int n,m;
    vector<int> v[32001];
    int indegree[32001]={0};
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    for(int i=1; i<=n; i++) {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for(int j=0; j<v[temp].size(); j++) {
            indegree[v[temp][j]]--;
            if(indegree[v[temp][j]] == 0) {
                q.push(v[temp][j]);
            }
        }
    }
}