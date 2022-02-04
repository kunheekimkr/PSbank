#include<iostream>
#include<queue>
using namespace std;
int n,k;
int visited[100001]={0,}; // visited 배열에 각 지점을 방문한 시간 저장
queue <int> q;
int search(){
    q.push(n);
    visited[n]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        if(p==k)
            return (visited[p]-1);
        if(p-1>=0 && visited[p-1]==0){
            visited[p-1]=visited[p]+1;
            q.push(p-1);
        }
        if(p+1<=100000 && visited[p+1]==0){
            visited[p+1]=visited[p]+1;
            q.push(p+1);
        }
        if(p*2<=100000 && visited[p*2]==0){
            visited[p*2]=visited[p]+1;
            q.push(p*2);
        }
    }

}

int main(){
    cin >> n >>k;
    cout << search();
}