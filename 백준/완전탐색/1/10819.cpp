#include<iostream>
using namespace std;
int n;
int arr[8];
int shuffled[8];
bool visited[8]={false,};
int answer=0;

int abs(int n){
    if(n>=0)
        return n;
    else
        return -n;
}

void search(int num){
    if(num == n){
        int result=0;
        for(int i=0; i<n-1; i++){
            result += abs(shuffled[i]-shuffled[i+1]);
        }
        if(result >answer)
            answer=result;
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i])
            continue;
        visited[i]=true;
        shuffled[num]= arr[i];
        search(num+1);
        visited[i]=false;
    }
}

int main(){
    cin >>n;
    for(int i=0; i<n; i++)
        cin >> arr[i]; 
    search(0);
    cout << answer;
}