#include<iostream>
#include<algorithm>
using namespace std;

//structure of a rectangle
// (x1,y1) and (x2,y2) are the lower-left and upper-right coordinates
// function area() returns the area of a rectangle
struct Rect {
    int x1, x2, y1, y2;
    int area() {
        return (y2-y1) * (x2-x1);
    }
};

//function that calculates the intersected part of two rectangles and returns the area of it
int intersect (Rect p, Rect q){
    int xoverlap= max(0,min(p.x2,q.x2) - max(p.x1, q.x1));
    int yoverlap= max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return xoverlap*yoverlap;
}

int main(){
    Rect board1, board2 ,truck;
    cin >> board1.x1 >> board1.y1 >> board1.x2 >> board1.y2;
    cin >> board2.x1 >> board2.y1 >> board2.x2 >> board2.y2;
    cin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;
    int ans=board1.area()+board2.area()-intersect(board1, truck) - intersect(board2, truck);
    cout << ans;
}