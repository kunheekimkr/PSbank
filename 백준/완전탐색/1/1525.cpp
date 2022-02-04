#include<iostream>
#include<queue>
#include<string>
#include<set>
using namespace std;
string start;
string finish="123456780";
set<string> visited;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int search(){
    queue <pair <string, int >> q;
    q.push(make_pair(start,0));
    visited.insert(start);
    while(!q.empty()){
        string current=q.front().first;
        int count= q.front().second;
        q.pop();
        
        if(current == finish)
            return count;
        
        int zero= current.find('0'); //0의 위치를 찾아 좌표로 만듬
        int x= zero / 3;
        int y= zero % 3;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if( nx >=0 && nx <3 && ny >=0 && ny<3 ){
                string next=current;
                char temp=next[3*x+y]; //(x,y) 와 (nx,ny) 를 교환
                next[3*x+y]=next[3*nx+ny];
                next[3*nx+ny]=temp;
                if(visited.find(next)==visited.end()){
                    visited.insert(next);
                    q.push(make_pair(next,count+1));
                }
            }
        }
    }
    return -1;
}
int main(){
    for(int i=0; i<9; i++){
        char c;
        cin >> c;
        start+=c;
    }
    cout << search();
    
}