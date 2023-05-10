#include<iostream>
#include<cstring>

using namespace std;

int m, n;
int arr[51][51];
bool visited[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool dfs(int y, int x) {
    if(visited[y][x])
        return false;
    visited[y][x] = true;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if(arr[ny][nx] == 1)
            dfs(ny, nx);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        int k;
        cin >> m >> n >> k;
        while(k--) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        int cnt =0 ;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j] == 1 && !visited[i][j])
                    if(dfs(i, j))
                        cnt++;
            }
        }
        cout << cnt << '\n';
    }
}