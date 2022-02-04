#include<iostream>
#include<string>
#include<queue>
using namespace std;
int map[100][100];
bool visited[100][100];
int shortest[100][100];
int n,m;
int answer=10000;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a,b));
    shortest[a][b]=0;
    while(q.empty() == false){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx < m && ny >=0 && ny <= n){
                if(map[nx][ny]==1){ //다음 칸이 벽인 경우
                    if(shortest[nx][ny]>shortest[x][y]+1){ //다음 칸까지의 거리의 최소값보다 현재 칸까지의 거리+1이 더 짧으면 현재 칸에서 다음칸으로 이동
                        shortest[nx][ny]=shortest[x][y]+1;
                        q.push(make_pair(nx,ny));
                    }
                }
                else{ //다음 칸이 벽이 아닌 경우
                    if(shortest[nx][ny]>shortest[x][y]){ //다음 칸까지의 거리 최소값보다 현재 칸까지가 더 짧으면 현재 칸에서 다음칸으로 이동
                        shortest[nx][ny]=shortest[x][y];
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m;i++){
        string temp;
        cin >> temp;
        for(int j=0; j<n; j++){
            map[i][j]=temp[j]-'0';
            shortest[i][j]=10000;
        }
    }
    BFS(0,0);
    cout << shortest[m-1][n-1];
}
