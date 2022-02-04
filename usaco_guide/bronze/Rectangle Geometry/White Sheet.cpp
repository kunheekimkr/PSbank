#include<iostream>
#include<algorithm>
using namespace std;

struct Rect {
    long long x1, x2, y1, y2;
    long long area() {
        return (y2-y1) * (x2-x1);
    }
};

long long intersect (Rect p, Rect q){
    long long xoverlap= max((long long) 0, min(p.x2,q.x2) - max(p.x1, q.x1));
    long long yoverlap= max((long long) 0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return xoverlap*yoverlap;
}

long long intersect_three (Rect p, Rect q, Rect r){
    long long xoverlap= max((long long)0, min(min(p.x2,q.x2),r.x2) - max(max(p.x1, q.x1),r.x1));
    long long yoverlap= max((long long)0, min(min(p.y2, q.y2),r.y2) - max(max(p.y1, q.y1),r.y1));
    return xoverlap*yoverlap;
}

int main(){
    Rect w, b1, b2;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    
    long long visible=w.area()-intersect(w,b1) -intersect(w,b2)+intersect_three(w,b1,b2);
    if(visible >0)
        cout << "YES";
    else
        cout << "NO";
}