#include<iostream>
using namespace std;
int main(){
    int r,c;
    cin >> r >> c;
    int arr[r][c];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }

    if(r%2){//짝수행의 경우 오른쪽끝까지-1칸아래-왼쪽끝까지-1칸아래...반복
        for(int i=0; i<r-1; i++){
            for(int j=1; j<c; j++){
                if(i%2==0)
                    cout <<'R';
                else
                    cout <<'L';
            }
            cout << 'D';;
        }
        for(int j=1; j<c; j++){
                cout <<'R';
        }       
    }
    else if (c%2){//짝수행의 경우 아래쪽끝까지-1칸오른쪽-위쪽끝까지-1칸오른쪽...반복
        for(int i=0; i<c-1; i++){
            for(int j=1; j<r; j++){
                if(i%2==0)
                    cout <<'D';
                else
                    cout <<'U';
            }
            cout << 'R';
        }
        for(int j=1; j<r; j++){
                cout <<'D';
        }      
    }
    //홀수행 홀수열의 경우 좌표(x,y)의 x+y가 홀수인 점 한 지점을 제외하고 모두 방문 가능
    // 짝수행일때와 같이 좌우로 반복하며 이동하다 제외할 칸이 있는 행에서는 위아래로 한칸씩 지그재그로 이동
    else{ 
        int min=1001;
        int min_x,min_y;
        for(int i=0; i<r; i++){ //최소 점의 좌표 탐색
            for(int j=0; j<c; j++){
                if((i+j)%2!=0){
                    if(min > arr[i][j]){
                        min=arr[i][j];
                        min_y=i;
                        min_x=j;
                    }
                }
            }
        }

        for(int i=0; i<min_y; i++){ //최소 점의 행에 도달하기 전까지 가로로 끝까지 지그재그 이동
            for(int j=0; j<c-1;j++){
                if(i%2==0)
                    cout << 'R';
                else
                    cout << 'L';
            }
            cout << 'D';
        }

        if(min_y%2==0){ //min_y가 짝수라면 위의 단계 결과 왼쪽에 도달하므로 오른쪽으로 위아래 지그재그 이동
            for(int i=0; i<min_x; i++){
                if(i%2==0)
                    cout <<'D';
                else
                    cout <<'U';
                cout << 'R';
            }
            for(int i=min_x; i<c-1; i++){
                cout << 'R';
                if(i%2==0)
                    cout <<'D';
                else
                    cout <<'U';
            }
        }
        else{ //min_y가 홀수라면 위의 단계 결과 오른쪽에 도달하므로 왼쪽으로 위아래 지그재그 이동
            for(int i=0; i<c-min_x-1; i++){
                if(i%2==0)
                    cout <<'D';
                else
                    cout <<'U';
                cout << 'L';
            }
            for(int i=0; i<min_x; i++){
                cout << 'L';
                if(i%2==0)
                    cout <<'U';
                else
                    cout <<'D';
            }            
        }

        for(int i=min_y+1; i<r-1; i++){ //마지막 점까지 다시 가로로 끝까지 지그재그 이동
            cout << 'D';
            for(int j=0; j<c-1;j++){
                if(i%2==0)
                    cout << 'R';
                else
                    cout << 'L';
            }
        }    
    }

}