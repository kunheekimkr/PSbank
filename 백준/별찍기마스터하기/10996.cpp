#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=n; j++){
            if(i%2==1){
                if(j%2==1)
                    cout << '*';
                else
                    cout << ' ';
            }
            else{
                if(j%2==1)
                    cout << ' ';
                else
                    cout << '*';                
            }

        }
        cout << endl;
    }
}