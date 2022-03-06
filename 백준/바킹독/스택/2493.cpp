#include<iostream>
#include<utility>
#include<stack>
using namespace std;

int n;
stack< pair<int,int> > tower; //first-타워의 높이 second-타워의 번호
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >>n;
    tower.push( make_pair(100000001, 0) );
    for(int i=1; i<=n; i++){
        int height;
        cin >> height;
        while(tower.top().first < height){
            tower.pop();
        }
        cout << tower.top().second << ' ';
        tower.push( make_pair(height, i) );
    }
}