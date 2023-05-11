#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
int m,n,h;
int arr[101][101][101] = { 0, };

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

typedef struct point {
    int x;
    int y;
    int z;
} point;
queue <point> q;
int cnt = 0; // num of 0s.

int bfs () {
    while (!q.empty()) {
        point p = q.front();
        q.pop();
        for(int i=0;i<6;i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if(arr[nx][ny][nz] == 0) {
                arr[nx][ny][nz] = arr[p.x][p.y][p.z] + 1;
                q.push({nx,ny,nz});
                cnt--;
            }
            if (cnt == 0 )
                return arr[p.x][p.y][p.z];
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> h;

    for(int i=0;i<h;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1) {
                    q.push({i,j,k});
                }
                else if(arr[i][j][k] == 0) {
                    cnt++;
                }
            }
        }
    }
    // bfs
    int result = cnt ==0 ? 0 : bfs();
    cout << result;
}