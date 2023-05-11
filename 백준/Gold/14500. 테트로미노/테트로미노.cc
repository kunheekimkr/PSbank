#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int arr[501][501];
bool visited[501][501];
int result = 0;
int sum = 0;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int x, int y, int sum, int cnt) {
    if(cnt == 4) {
        result = max(result, sum);
        return;
    }

    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx,ny,sum+arr[nx][ny],cnt+1);
            visited[nx][ny] = false;
        }
    }
}

//  ㅗ ㅏ ㅓ ㅜ
int ex[4][4] = {{0,1,2,1},{0,0,0,1}, {0,0,0,-1}, {0,1,2,1}};
int ey[4][4] = {{0,0,0,-1},{0,1,2,1}, {0,1,2,1}, {0,0,0,1}}; 

void checketc (int x, int y) {
    for(int i=0;i<4;i++) {
        sum = 0;
        bool flag = true;
        for(int j=0;j<4;j++) {
            int nx = x + ex[i][j];
            int ny = y + ey[i][j];

            if (nx <0 || nx >= n || ny < 0 || ny >= m) {
                flag = false;
                break;
            }
            sum += arr[nx][ny];
        }
        if (flag)
            result = max(result, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++) {

            // DFS 로 4가지 모양 검사
            visited[i][j] = true;
            dfs(i,j, arr[i][j], 1);
            visited[i][j] = false;

            // ㅗ 모양 검사
            checketc(i,j);
        }
    }

    cout << result;
}