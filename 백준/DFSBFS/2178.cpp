#include<iostream>
#include<queue>
using namespace std;

struct point{
    int x,y;
};

int main(){
    int n,m;
    cin >> n >> m;
    int searched[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            char temp;
            cin >> temp;
            if(temp=='0')
                searched[i][j]=-1;
            else
                searched[i][j]=0;
        }
    }
    searched[0][0]=1;
    queue <point> q;
    q.push({0,0});
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
                if(searched[ny][nx]==0){ 
                    searched[ny][nx] =searched[y][x]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

    cout << searched[n-1][m-1];
}