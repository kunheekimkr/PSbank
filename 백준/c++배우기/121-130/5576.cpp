#include<iostream>
using namespace std;
int main(){
    int w[10];
    int k[10];
    for(int i=0; i<10; i++){
        cin >> w[i];
    }
    for(int i=0; i<10; i++){
        cin >> k[i];
    }

    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if(w[i]>w[j]){
                int temp=w[i];
                w[i]=w[j];
                w[j]=temp;
            }
            if(k[i]>k[j]){
                int temp=k[i];
                k[i]=k[j];
                k[j]=temp;
            }
        }
    }
    cout << w[9]+w[8]+w[7] << ' ' << k[9]+k[8]+k[7];
}