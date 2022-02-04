#include<iostream>
using namespace std;
struct Man{
    int x;
    int y;
};

int main(){
    int n;
    cin >> n;
    Man m[n];
    for(int i=0; i<n; i++){
        cin >> m[i].x >> m[i].y; 
    }

    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(m[i].x<m[j].x && m[i].y<m[j].y)
                cnt++;
        }
        cout << cnt+1 << ' ';
    }
}