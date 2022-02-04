#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class point {
    public:
        int x;
        int y;
        point(int a, int b) {
            x=a;
            y=b;
        }
};

bool compare(point a, point b){
    if(a.y < b.y)
        return true;
    else if (a.y == b.y){
        if(a.x<b.x) 
            return true;
        else
            return false;
    }
    else
        return false;

}

int main(){
    int n;
    cin >> n;

    int x,y;
    vector<point> v;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back(point(x,y));
    }

    sort(v.begin(),v.end(),compare);

    for(int i=0; i<n; i++){
        cout << v[i].x << ' ' << v[i].y << '\n';

    }
}