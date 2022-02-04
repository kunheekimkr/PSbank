#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int x1,x2,y1,y2;
    cin>> x1 >> y1 >> x2 >> y2;
    int x3,x4,y3,y4;
    cin >> x3 >> y3 >> x4 >> y4;

    //Case 1: the second board fully covers the first board
    if (x3 <= x1 && y3 <= y1 && x2 <= x4 && y2 <= y4)
        cout << 0;
    //Case 2: the second board covers the bottom of the first board
    else if (x3 <= x1 && x2 <= x4 && y3 <= y1 && y4 <= y2)
        cout << (x2-x1)*(y2-y4);
    //Case 3: the second board covers the top of the first board
    else if (x3 <= x1 && y1 <= y3 && x2 <= x4 && y2 <= y4)
        cout << (x2-x1)*(y3-y1);    
    //Case 4: the second board covers the left of the first board
    else if (x3 <= x1 && y3 <= y1 && x4 <= x2 && y2 <= y4)
        cout << (x2-x4)*(y2-y1);
    //Case 5: the second board covers the right of the first board
    else if (x1 <= x3 && y3 <= y1 && x2 <= x4 && y2 <= y4)
        cout << (x3-x1)*(y2-y1);
    //Case 6: Other cases(Covering the corner, no intersection)
    else
        cout << (x2-x1)*(y2-y1);    
}   