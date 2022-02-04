#include<iostream>
#include<queue>
using namespace std;
struct point{
    int x, y;
};

int main(){
    int m,n;
    cin >> m >> n;
    int graph[n][m]; // 각 점이 익을때까지 걸리는 시간을 저장
    queue<point> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j]==1){
                q.push({j,i});
            }
        }
    }
    while(!q.empty()){
        int x =q.front().x;
        int y =q.front().y;
        q.pop();
        struct point around[4]; //주변 4개 점들을 탐색하기 위해 사용
        around[0].x=1;
        around[0].y=0;
        around[1].x=-1;
        around[1].y=0;
        around[2].x=0;
        around[2].y=-1;
        around[3].x=0;
        around[3].y=1;
        for(int i=0; i<4; i++){
            int nx=x+around[i].x;
            int ny=y+around[i].y;

            if(0<=nx && nx <m && 0<=ny && ny <n){ //다음 점이 상자 범위 내에 있는지 확인
                if(graph[ny][nx]==0){ 
                    graph[ny][nx] =graph[y][x]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int result=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==0){
                cout << "-1";
                return 0;
            }
            if(result < graph[i][j]){
                result=graph[i][j];
            }
        }
    }
    cout << result-1;
}