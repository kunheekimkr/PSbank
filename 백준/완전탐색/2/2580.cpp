#include<iostream>
using namespace std;
int board[9][9];
bool row[9][10]; // row[a][b]: a번째 행에 b라는 숫자가 있는지를 저장
bool col[9][10]; // col[a][b]: a번째 열에 b라는 숫자가 있는지를 저장
bool square[9][10]; // square[a][b]: a번째 사각형에 b라는 숫자가 있는지를 저장

void search(int cnt){//cnt 번째 칸을 탐색
    if(cnt==81){
        for (int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }    
        exit(0);
    }
    int x=cnt/9;
    int y=cnt%9;
    if(board[x][y]==0){
        for(int i=1; i<10; i++){           
            if(row[x][i]==false && col[y][i]==false && square[(x/3)*3+y/3][i]==false){
                //board[x][y] 에 i를 넣어도 문제가 없다면 i를 대입하고 다음 칸 탐색
                row[x][i]=true;
                col[y][i]=true;
                square[(x/3)*3+(y/3)][i]=true;
                board[x][y]=i;
                search(cnt+1);
                //이후 탐색에서 문제가 생겼다면 다시 돌아와서 이전 상태로 되돌리고 board[x][y]에 다음 i 시도
                board[x][y]=0;                   
                row[x][i]=false;
                col[y][i]=false;
                square[(x/3)*3+(y/3)][i]=false;             
            }
        }
    }
    else
        search(cnt+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
            if(board[i][j]!=0)
                row[i][board[i][j]]=true;
                col[j][board[i][j]]=true;
                square[(i/3)*3+j/3][board[i][j]]=true;
        }
    } 
    search(0);
}   