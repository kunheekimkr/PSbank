#include<iostream>
#include<algorithm>
using namespace std;
int main(){

    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int a1,a2,b1,b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int min_x = min(x1,a1);
    int max_x = max(x2,a2);
    int min_y = min(y1,b1);
    int max_y = max(y2,b2);

    int side= max(max_x - min_x,max_y - min_y);
    int ans= side*side;
    cout << ans;
}  