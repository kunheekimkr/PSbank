#include<iostream>
using namespace std;
int main(){
    int arr[8];
    int asc=0, desc=0;
    for(int i=0; i<8; i++){
        cin >> arr[i];
        if(arr[i]==i+1)
            asc++;
        else if (arr[i]==8-i)
            desc++;
    }

    if(asc==8)
        cout << "ascending";
    else if (desc==8)
        cout << "descending";
    else
        cout << "mixed";
}