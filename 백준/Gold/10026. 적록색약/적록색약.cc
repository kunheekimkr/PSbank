#include<iostream>
#include<cstring>

using namespace std;
int n;
char rgb [101][101] = {0,};
char rb [101][101] = {0,};
bool visited[101][101];
int cnt =0;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs_on_rgb(int y, int x) {
    if(visited[y][x]) return;
    visited[y][x] = true;   
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i]; 
        if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
        if(rgb[ny][nx] == rgb[y][x]) {
            dfs_on_rgb(ny, nx);
        }
    }
}

void dfs_on_rb(int y, int x) {
    if(visited[y][x]) return;
    visited[y][x] = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i]; 
        if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
        if(rb[ny][nx] == rb[y][x]) {
            dfs_on_rb(ny, nx);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> rgb[i][j];
           rb[i][j] = rgb[i][j] == 'G' ? 'R' : rgb[i][j];
        }
    }
    // DFS on rgb
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            if(!visited[i][j]) {
                dfs_on_rgb(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    // DFS on rb
    memset(visited, false, sizeof(visited));
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            if(!visited[i][j]) {
                dfs_on_rb(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}