#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    while(k--){
        int max_w, max_h;
        cin >> max_w >> max_h;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int width=x2-x1;
        int height=y2-y1;
        int w, h;
        cin >> w >> h;


        int move_x=-1, move_y=-1;
        if(width+w <= max_w)
            move_x = max(0, w-max(x1,max_w-x2));
        if(height + h <= max_h)
            move_y = max(0, h-max(y1,max_h-y2));
            
        if(move_x ==-1 && move_y !=-1)
            cout << move_y << '\n';
        else if (move_x !=-1 && move_y == -1)
            cout << move_x << '\n';
        else if (move_x != -1 && move_y !=-1)
            cout << min(move_x, move_y) << '\n';
        else
            cout << -1 << '\n';
    }
}