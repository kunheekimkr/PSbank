#include<iostream>
#include<bitset>
using namespace std;

int arr[32];

int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        int temp;
        for(int i=0; i<32; i++){
            arr[i]= (a >> i) & 1;
            if(arr[i]==1)
                temp=i;
        }
        for(int i=0; i<temp; i++){
            if(arr[i]==1)
                cout << i << ' ';
        }
        cout << temp << endl;
    }
}