#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int total = b-a +d-c;
    int intersection = max(0, min(b,d) - max(a,c));
    int ans = total - intersection;
    cout << ans;
}