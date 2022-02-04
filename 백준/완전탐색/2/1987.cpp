#include<iostream>
using namespace std;
int r,c;
char board[20][20];
bool visited[26];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans=0;
void search(int x, int y, int cnt){
    if(cnt> ans)
        ans=cnt;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx <r && ny>=0 && ny<c){
            if(visited[board[nx][ny]-'A']==false){
                visited[board[nx][ny]-'A']=true;
                search(nx,ny,cnt+1);
                visited[board[nx][ny]-'A']=false;
            }
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>> board[i][j];
        }
    }
    visited[board[0][0]-'A']=true;
    search(0,0,1);
    cout << ans;
}