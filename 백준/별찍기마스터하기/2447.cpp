#include<iostream>
using namespace std;
void star(int i, int j, int n){
    if(n==0)
        cout << '*';
    else{
        if (i%3==2 && j%3==2)
            cout << ' ';
        else{
            star((i+2)/3,(j+2)/3,n/3);
        }
    }

}
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n;j++ ){
            star(i,j,n);
        }
        cout << endl;
    }
}