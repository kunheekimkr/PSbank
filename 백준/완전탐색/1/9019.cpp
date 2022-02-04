#include<iostream>
#include<string>
#include<queue>
using namespace std;
int a,b;
bool visited[10000];

int calculate(int n, char c){
    if (c == 'D'){
        return (n*2)%10000;
    }
    else if (c == 'S'){
        if (n ==0)
            return 9999;
        else
            return n-1;
    }
    else if (c == 'L'){
        return (n%1000)*10 + n/1000;
    }
    else if (c == 'R'){
        return (n%10)*1000 + n/10;
    }
}

string search(int n){
    queue<pair<int,string>> q;
    q.push(make_pair(n,""));
    visited[n]=true;

    while(!q.empty()){
        int current=q.front().first;
        string s=q.front().second;
        q.pop();
        if (current == b)
            return s;
        int next;
        char c;

        c='D';
        next= calculate(current,c);
        if(!visited[next]){
            visited[next]=true;
            q.push(make_pair(next,s+c));
        }

        c='S';
        next= calculate(current,c);
        if(!visited[next]){
            visited[next]=true;
            q.push(make_pair(next,s+c));
        } 

        c='L';
        next= calculate(current,c);
        if(!visited[next]){
            visited[next]=true;
            q.push(make_pair(next,s+c));
        } 

        c='R';
        next= calculate(current,c);
        if(!visited[next]){
            visited[next]=true;
            q.push(make_pair(next,s+c));
        } 
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        for(int i=0; i<10000; i++)
            visited[i]=false;
        cout << search(a) << endl;
    }
}