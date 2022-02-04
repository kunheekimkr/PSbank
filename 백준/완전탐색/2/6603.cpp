#include<iostream>
#include<string>
using namespace std;
int k;
int s[12];
int temp[12];
void backtracking(int cnt, int idx){ //cnt=현재까지 넣은 숫자의 수 ,idx= 마지막에 넣은 숫자의 크기순 위치
    if(cnt==6){
        for (int i=0; i<6; i++)
            cout << temp[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=idx;i<k;i++){
        temp[cnt]=s[i];
        backtracking(cnt+1,i+1);
    }
}

int main(){
    while (true){
        for(int i=0; i<12; i++){
            s[i]=0;
            temp[i]=0;
        }
        cin >> k;
        if(k==0)
            break;
        for(int i=0; i<k; i++){
            cin >> s[i];
        }
        backtracking(0,0);
        cout << '\n';
    }
}