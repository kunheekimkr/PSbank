#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
int arr[8] = {0,};
bool visited[8] = {false,};

void dfs(int num, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[cnt] = v[i];
            dfs(i+1, cnt+1);
            visited[i]=false;
        }
    }

}

int main(){
    cin >> n >> m;
    v.resize(n);

    for(int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    dfs(0,0);
}