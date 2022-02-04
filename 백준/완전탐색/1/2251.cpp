#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
int a, b, c;
bool visited[201][201][201];
vector<int> v;

void search(){
    queue <tuple<int,int,int>> q;
    q.push(make_tuple(0,0,c));
    while(!q.empty()){
        int curr_a=get<0>(q.front());
        int curr_b=get<1>(q.front());
        int curr_c=get<2>(q.front());
        q.pop();
        if(!visited[curr_a][curr_b][curr_c]){
            visited[curr_a][curr_b][curr_c]=true;
            
            if (curr_a==0)
                v.push_back(curr_c);
            
            //a->b
            if(curr_a+curr_b>b)
                q.push(make_tuple(curr_a+curr_b-b,b,curr_c));
            else
                q.push(make_tuple(0,curr_a+curr_b,curr_c));

            //b->a
            if(curr_a+curr_b>a)
                q.push(make_tuple(a,curr_a+curr_b-a,curr_c));
            else
                q.push(make_tuple(curr_a+curr_b,0,curr_c));

            //a->c
            if(curr_a+curr_c>c)
                q.push(make_tuple(curr_a+curr_c-c,curr_b,c));
            else
                q.push(make_tuple(0,curr_b,curr_a+curr_c));

            //c->a
            if(curr_a+curr_c>a)
                q.push(make_tuple(a,curr_b,curr_a+curr_c-a));
            else
                q.push(make_tuple(curr_a+curr_c,curr_b,0));                

            //b->c
            if(curr_b+curr_c>c)
                q.push(make_tuple(curr_a,curr_b+curr_c-c,c));
            else
                q.push(make_tuple(curr_a,0,curr_b+curr_c));

            //c->b
            if(curr_b+curr_c>b)
                q.push(make_tuple(curr_a,b,curr_b+curr_c-b));
            else
                q.push(make_tuple(curr_a,curr_b+curr_c,0));
        }
    }
}

int main(){
    cin >> a >> b >> c;
    search();
    sort(v.begin(),v.end());
    for(int i=0; i<v.size();i++)
        cout << v[i] << ' ';
}