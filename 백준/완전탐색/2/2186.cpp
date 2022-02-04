#include<iostream>
#include<string>
using namespace std;

int n,m,k;
char board[100][100];
string word;
int dp[100][100][80]; // dp[x][y][index] = (x,y) 지점의 단어를 index번째에서 지날 때 뒤에 word가 나오는 조합의 개수

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int search(int x, int y, int index){
    if(dp[x][y][index]!=-1) //이미 한번 탐색한 경우 그 값을 리턴
        return dp[x][y][index];

    if(index>=word.size()) //정확하게 word를 완성한 경우
        return 1;
    
    dp[x][y][index]=0; //(x,y) 를 index번째에서 지나는 경우 탐색
    for(int i=0; i<4; i++){
        for(int j=1; j<=k; j++){
            int nx= x + j*dx[i];
            int ny= y + j*dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(board[nx][ny]==word[index])
                    dp[x][y][index]+=search(nx,ny,index+1);
            }
        }
    }
    return dp[x][y][index];   
}

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    cin >> word;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            for(int k=0; k<80; k++){
                dp[i][j][k]=-1;
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                ans+=search(i,j,1);
            }
        }
    }
    cout << ans;
}
