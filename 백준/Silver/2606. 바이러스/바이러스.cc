#include<iostream>
#include<cstring>

using namespace std;
int n;
int arr[101][101];
bool visited[100];

void dfs (int a) {
    if (visited[a])
        return;
    visited[a] = true;
    for (int i=1; i<=n; i++) {
        if (arr[a][i] == 1) {
            dfs(i);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(arr, 0, sizeof(arr));
    memset(visited, false, sizeof(visited));
    cin >> n;
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;        
    }
    dfs(1);
    int cnt = 0;
    for (int i=1; i<=n; i++ ) {
        if(visited[i])
            cnt++;
    }
    cout << cnt-1 << '\n';
}