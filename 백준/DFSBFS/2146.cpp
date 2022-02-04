#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct point{
    int x,y;
};

int main(){
    int n;
    cin >> n;
    int map[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> map[i][j];
        }
    }
    queue<point> q;
    struct point around[4]; //주변 4개 점들을 탐색하기 위해 사용
    around[0].x=1;  
    around[0].y=0;
    around[1].x=-1;
    around[1].y=0;
    around[2].x=0;
    around[2].y=-1;
    around[3].x=0;
    around[3].y=1;
    int island=2;
    for(int i=0; i<n; i++){ // bfs 를 통해 같은 섬끼리 번호를 매김!
            for(int j=0; j<n;j++){
                if (map[i][j]==1){ // 여기고쳐야됨!
                    map[i][j]=island;
                    q.push({j,i});
                    while(!q.empty()){
                        int x =q.front().x;
                        int y =q.front().y;
                        q.pop();
                        for(int i=0; i<4; i++){
                            int nx=x+around[i].x;
                            int ny=y+around[i].y;
                            if(0<=nx && nx <n && 0<=ny && ny <n){ //다음 점이 상자 범위 내에 있는지 확인
                                if(map[ny][nx]==1){ 
                                    map[ny][nx] =island;
                                    q.push({nx,ny});
                                }
                            }
                        }
                    }
                    island++;
                }
            }
    }

    int dist[n][n]={0,};  //k번 섬으로부터의 거리를 저장
    int answer=201;
    for(int k=2; k<island; k++){ //k번 섬에 대한 bfs 탐색
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j]=-1;
                if(map[i][j]==k){
                    q.push({j,i});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x =q.front().x;
            int y =q.front().y;
            q.pop();
            for(int i=0; i<4; i++){
                int nx=x+around[i].x;
                int ny=y+around[i].y;
                if(0<=nx && nx <n && 0<=ny && ny <n){ //다음 점이 상자 범위 내에 있는지 확인
                    if(dist[ny][nx]==-1){ 
                        dist[ny][nx]=dist[y][x]+1;
                        q.push({nx,ny});
                    }
                }
            }            
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] !=0 && map[i][j] !=k) {// (i,j)가 다른 섬인 경우
                    if(answer >(dist[i][j]-1)){
                        answer = dist[i][j] -1; //answer 에 최소 다리 길이 저장
                    }
                }
            }
        }
    }
    cout << answer;

}