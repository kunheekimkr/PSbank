#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    double sum=0, max=0;
    for(int i=1; i<=n; i++)
    {
        double point;
        cin >> point;
        sum+=point;
        if(point>max)
            max=point;
    }
    cout << 100*sum/(n*max);
}