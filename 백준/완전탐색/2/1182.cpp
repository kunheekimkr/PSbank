#include<iostream>
using namespace std;
int n,s;
int num[20];
int answer=0;
int temp[20];

void search(int cnt, int idx, int size){
    if (cnt==size){        
        int sum=0;
        for(int i=0; i<size; i++)
            sum+=temp[i];
        if(sum == s){
            answer++;
        }
        return;
    }

    for (int i=idx; i<n; i++){
        temp[cnt]=num[i];
        search(cnt+1,i+1,size);
    }

}

int main(){
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> num[i];
    for(int i=1; i<=n; i++){
        search(0,0,i);
    }
    cout << answer;
}