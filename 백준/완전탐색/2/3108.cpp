#include<iostream>
using namespace std;
int board[2001][2001]; //(x,y) 를 board(2*(x+500),2*(y+500))에 저장하자. 이렇게 하면 음수 좌표도 양수 좌표로 저장 가능하며, 사각형 안에 사각형이 들어가는 예외처리도 가능하다.

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void search(int y, int x){
    if(y>=0 && y<=2000 && x>=0 && x<=2000){
        if(board[y][x]==1){
            board[y][x]=2; //한번 지나간 점은 2로 표시
            for(int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                search(ny,nx);
            }
        }
    }
}

int main(){
    int n;
    cin >>n;

    for(int i=0; i<2001; i++)
        for(int j=0; j<2001; j++)
            board[i][j]=0;

    while(n--){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
    
    //사각형의 둘레에 포함되는 점(x,y)에 대해 board[2(y+500)][2(x+500)]=1 로 저장하자
        for(int i=2*(x1+500); i<=2*(x2+500); i++){
            board[2*(y1+500)][i]=1;
            board[2*(y2+500)][i]=1;
        }

        for(int i=2*(y1+500); i<=2*(y2+500); i++){
            board[i][2*(x1+500)]=1;
            board[i][2*(x2+500)]=1;
        }
    }

    int ans=0;
    for(int i=0;i<2001;i++){
        for(int j=0; j<2001; j++){
            if(board[i][j]==1){
                search(i,j);
                ans++;
            }
        }
    }


    if(board[1000][1000]==2) //(0,0)에서 연필을 내린 채로 시작하므로 이 점을 지나는 경우 -1
        ans--;

    cout << ans;
}