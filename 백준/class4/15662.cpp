#include<iostream>
using namespace std;

int n, m;
int arr[9] = {0,};
bool visited[9] = {false,};

void dfs(int num, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=num; i<=n; i++){
        if(visited[i] == false || i == num){
            visited[i] = true;
            arr[cnt] = i;
            dfs(i, cnt+1);
            visited[i]=false;
        }
    }

}

int main(){
    cin >> n >> m;
    dfs(1,0);
}